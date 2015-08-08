package com.bjt.ShapeAnalyzer;

import org.postgresql.PGConnection;

import java.sql.Connection;
import java.sql.DriverManager;
import java.io.File;

public class App 
{
	public static void main( String[] args ) {
		try {
			loadLib("com_bjt_ShapeAnalyzer_App.so");
			loadLib("libproj.so");

			double[] latlongs = new double[]{53.2, -0.75,    53.2, -0.6};
			int maxPercentage = getmaxpercentage(latlongs);
			System.out.println(String.format("The result is %d", maxPercentage));
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

	private static void loadLib(final String lib) {
		final String curdir = System.getProperty("user.dir");
		final File libFile = new File(curdir, lib);
		System.load(libFile.getAbsolutePath());
	}

	public static native int getmaxpercentage(double[] latLongs);
}
