package com.bjt.ShapeAnalyzer;

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
import java.util.ArrayList;
import java.util.List;

public class App 
{
	public static void main( String[] args ) {
		try {
			//loadLib("com_bjt_ShapeAnalyzer_App.so");
			Double[] latlongs = readLatLongsFromGpxFile(new File(args[0]));
			double maxPercentage = getmaxpercentage(latlongs);
			System.out.println(String.format("The result is %.6f", maxPercentage));
			/*            
										Class.forName("org.postgresql.Driver");
										String connStr = "jdbc:postgresql://192.168.1.23:5432/junctions";
										System.out.println("Connecting...");
										try (final Connection connection = DriverManager.getConnection(connStr, "osm", "osm")) {

										System.out.println("Connected to postgres.");
										final PGConnection pgConnection = (PGConnection) connection;
										pgConnection.addDataType("geometry", Class.forName("org.postgis.PGgeometry"));
										}
			 */
		}catch(Exception e) {
			e.printStackTrace(System.err);
			System.exit(1);
		}
	}

	private static Double[] readLatLongsFromGpxFile(File file) throws ParserConfigurationException, IOException, SAXException, XPathExpressionException {
		final DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
		final DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
		final Document document = documentBuilder.parse(file);
		final XPathFactory xPathFactory = XPathFactory.newInstance();
		final XPath xPath = xPathFactory.newXPath();
		final XPathExpression xPathExpression = xPath.compile("gpx/trk/trkseg/trkpt");
		final NodeList nodes = (NodeList) xPathExpression.evaluate(document, XPathConstants.NODESET);
		final List<Double> doubles = new ArrayList<>();
		for(int i = 0; i < nodes.getLength(); i++) {
			final Node node = nodes.item(i);
			final NamedNodeMap attributes = node.getAttributes();
			Double lat = Double.parseDouble(attributes.getNamedItem("lat").getNodeValue());
			Double lon = Double.parseDouble(attributes.getNamedItem("lon").getNodeValue());
			doubles.add(lat);
			doubles.add(lon);
		}
		return doubles.toArray(new Double[]{});
	}

	private static void loadLib(final String lib) {
		final String curdir = System.getProperty("user.dir");
		final File libFile = new File(curdir, lib);
		System.load(libFile.getAbsolutePath());
	}

	public static native double getmaxpercentage(Double[] latLongs);
}
