package com.bjt.ShapeAnalyzer;

import org.postgis.LineString;
import org.postgis.PGgeometry;
import org.postgis.Point;
import org.postgresql.PGConnection;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.*;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.io.File;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Random;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

public class App 
{
	private static AtomicInteger countRead = new AtomicInteger(0);
	private static AtomicInteger countProcessed = new AtomicInteger(0);
	private static AtomicInteger countWritten = new AtomicInteger(0);
	private static AtomicBoolean allRead = new AtomicBoolean(false);

	private static LinkedBlockingQueue<RoadInfo> processingQueue = new LinkedBlockingQueue<>(10000); //read from DB, ready to process
	private static LinkedBlockingQueue<SteepnessInfo> writeQueue = new LinkedBlockingQueue<>(10000); //processed, ready to write back to DB

	private static Thread readThread = new Thread(() -> {		read();});
	private static Thread processThread =new Thread(() -> {process();});
	private static Thread writeThread = new Thread(() -> write());
	private static Thread reportthread = new Thread(() -> report());

	public static void main( String[] args ) {
		try {

			//loadLib("com_bjt_ShapeAnalyzer_App.so");
/*
			double[] latlongs = readLatLongsFromGpxFile(new File(args[0]));
			double maxPercentage = getmaxpercentage(latlongs);
			System.out.println(String.format("The result is %.6f", maxPercentage));
*/
			readThread.start();
			processThread.start();
			writeThread.start();
			reportthread.start();

			readThread.join();
			processThread.join();
			writeThread.join();

			reportthread.interrupt();
			reportthread.join(3000);

		}catch(Exception e) {
			e.printStackTrace(System.err);
			System.exit(1);
		}
	}

	public static void read() {
		try {
			Class.forName("org.postgresql.Driver");
			String connStr = "jdbc:postgresql://192.168.1.23:5432/osm";
			try (final Connection connection = DriverManager.getConnection(connStr, "osm", "osm")) {
				System.out.println("READ: Connected to postgres.");
				final PGConnection pgConnection = (PGConnection) connection;
				pgConnection.addDataType("geometry", Class.forName("org.postgis.PGgeometry"));
				final PreparedStatement preparedStatement = connection.prepareStatement(
						"select osm_id, ST_Transform(geometry, 4326) as geometry from osm_roads limit 10");
				try(final ResultSet resultSet = preparedStatement.executeQuery()) {
					while (resultSet.next()) {
						if (Thread.interrupted()) {
							System.out.println("READ: ending by request");
							return;
						}
						final long osmId = resultSet.getLong("osm_id");
						final PGgeometry pGgeometry = (PGgeometry) resultSet.getObject("geometry");
						final LineString lineString = (LineString) pGgeometry.getGeometry();
						final double[] latLongs = new double[lineString.numPoints() * 2];
						for(int i = 0; i < lineString.numPoints(); i++) {
							final Point point = lineString.getPoint(i);
							latLongs[i*2] = point.getY();
							latLongs[i*2+1] = point.getX();
						}
						final RoadInfo roadInfo = new RoadInfo(osmId, latLongs);
						countRead.incrementAndGet();
						processingQueue.put(roadInfo);
					}
					processingQueue.put(RoadInfo.End());
				}
			}
		}
		catch(Exception e) {
			System.out.println("READ: exception:");
			e.printStackTrace();
			writeThread.interrupt();
			processThread.interrupt();
		}
	}

	public static void process() {
		try {
			while(!Thread.interrupted()) {
				final RoadInfo roadInfo = processingQueue.take();
				if(roadInfo.isEnd()) {
					System.out.println("\nPROCESS: no more in processing queue");
					writeQueue.put(SteepnessInfo.End());
					return;
				}
				double maxPercentage = getmaxpercentage_test(roadInfo.getLatLongs());
				countProcessed.incrementAndGet();
				final SteepnessInfo steepnessInfo = new SteepnessInfo(roadInfo.getOsmId(), maxPercentage);
				writeQueue.put(steepnessInfo);
			}
			System.out.println("PROCESS: ending by request");
		}
		catch(InterruptedException e) {
			System.out.println("PROCESS: ending by request (ex)");
		}
		catch(Exception e) {
			System.out.println("PROCESS: exception:");
			e.printStackTrace();
			readThread.interrupt();
			writeThread.interrupt();
		}
	}

	public static void write() {
		try {
			Class.forName("org.postgresql.Driver");
			String connStr = "jdbc:postgresql://192.168.1.23:5432/osm";
			try (final Connection connection = DriverManager.getConnection(connStr, "osm", "osm")) {
				System.out.println("WRITE: Connected to postgres.");
				final PreparedStatement preparedStatement = connection.prepareStatement(
						"insert into steepness(osm_id, maxpercentage) values(?,?)");

				while (!Thread.interrupted()) {
					final SteepnessInfo steepnessInfo = writeQueue.take();
					if (steepnessInfo.isEnd()) {
						System.out.println("WRITE: no more in write queue");
						return;
					}
					preparedStatement.setLong(1, steepnessInfo.getOsmId());
					preparedStatement.setDouble(2, steepnessInfo.getMaxPercentage());
					preparedStatement.execute();
					countWritten.incrementAndGet();
				}
			}
			System.out.println("WRITE: ending by request");
		}catch(InterruptedException e) {
			System.out.println("WRITE: ending by request (ex)");
		} catch(Exception e) {
			System.out.println("WRITE: exception");
			e.printStackTrace();
			readThread.interrupt();
			processThread.interrupt();
		}
	}

	private static void report() {
		try {
			while (!Thread.interrupted()) {
				Thread.sleep(2000);
				System.out.print(String.format("\rRead: %d, processed %d, written %d",
						countRead.get(), countProcessed.get(), countWritten.get()));
			}
		}catch(InterruptedException e) {
		}
	}

	private static double[] readLatLongsFromGpxFile(File file) throws ParserConfigurationException, IOException, SAXException, XPathExpressionException {
		final DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
		final DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
		final Document document = documentBuilder.parse(file);
		final XPathFactory xPathFactory = XPathFactory.newInstance();
		final XPath xPath = xPathFactory.newXPath();
		final XPathExpression xPathExpression = xPath.compile("gpx/trk/trkseg/trkpt");
		final NodeList nodes = (NodeList) xPathExpression.evaluate(document, XPathConstants.NODESET);
		final double[] doubles = new double[nodes.getLength() * 2];
		for(int i = 0; i < nodes.getLength(); i++) {
			final Node node = nodes.item(i);
			final NamedNodeMap attributes = node.getAttributes();
			double lat = Double.parseDouble(attributes.getNamedItem("lat").getNodeValue());
			double lon = Double.parseDouble(attributes.getNamedItem("lon").getNodeValue());
			doubles[i*2] = lat;
			doubles[i*2+1] = lon;
		}
		return doubles;
	}

	private static void loadLib(final String lib) {
		final String curdir = System.getProperty("user.dir");
		final File libFile = new File(curdir, lib);
		System.load(libFile.getAbsolutePath());
	}

	public static native double getmaxpercentage(double[] latLongs);

	private static Random r = new Random();
	public static double getmaxpercentage_test(double[] latLongs) throws InterruptedException {
		Thread.sleep(1000);
		return r.nextDouble() * 0.25;
	}
}
