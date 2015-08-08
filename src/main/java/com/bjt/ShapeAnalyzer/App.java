package com.bjt.ShapeAnalyzer;

import org.postgresql.PGConnection;

import java.sql.Connection;
import java.sql.DriverManager;
import java.io.File;

public class App 
{
    public static void main( String[] args ) {
        try {
            final String curdir = System.getProperty("user.dir");
            final File libFile = new File(curdir, "com_bjt_ShapeAnalyzer_App.so");
						System.load(libFile.getAbsolutePath());

            int[] latlongs = new int[]{};
            int maxPercentage = getmaxpercentage(latlongs);
            System.out.println(String.format("The result is %d", maxPercentage));
            
            Class.forName("org.postgresql.Driver");
            String connStr = "jdbc:postgresql://192.168.1.23:5432/junctions";
            System.out.println("Connecting...");
            try (final Connection connection = DriverManager.getConnection(connStr, "osm", "osm")) {

                System.out.println("Connected to postgres.");
                final PGConnection pgConnection = (PGConnection) connection;
                pgConnection.addDataType("geometry", Class.forName("org.postgis.PGgeometry"));
            }
        }catch(Exception e) {
            e.printStackTrace(System.err);
            System.exit(1);
        }
    }

    public static native int getmaxpercentage(int[] latLongs);
}
