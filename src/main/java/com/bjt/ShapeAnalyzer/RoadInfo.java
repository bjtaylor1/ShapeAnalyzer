package com.bjt.ShapeAnalyzer;

/**
 * Created by Ben.Taylor on 09/08/2015.
 */
public class RoadInfo {
    private final long osmId;
    private final double[] latLongs;
    private final boolean _end;
    public boolean isEnd() {
        return _end;
    }

    public RoadInfo(long osmId, double[] latLongs) {
        this.osmId = osmId;
        this.latLongs = latLongs;
        _end = false;
    }

    private RoadInfo(boolean end) {
        _end = end;
        osmId = 0;
        latLongs = new double[0];
    }

    public static RoadInfo End() {
        return new RoadInfo(true);
    }

    public long getOsmId() {
        return osmId;
    }

    public double[] getLatLongs() {
        return latLongs;
    }
}

