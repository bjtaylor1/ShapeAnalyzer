package com.bjt.ShapeAnalyzer;

/**
 * Created by Ben.Taylor on 09/08/2015.
 */
public class SteepnessInfo {
    private final long osmId;
    private final double maxPercentage;
    private  final boolean _end;
    public SteepnessInfo(long osmId, double maxPercentage) {
        this.osmId = osmId;
        this.maxPercentage = maxPercentage;
        _end = false;
    }

    private SteepnessInfo(boolean end) {
        _end = end;
        osmId = 0;
        maxPercentage = 0;
    }

    public static SteepnessInfo End() {
        return new SteepnessInfo(true);
    }

    public boolean isEnd() {
        return _end;
    }

    public long getOsmId() {
        return osmId;
    }

    public double getMaxPercentage() {
        return maxPercentage;
    }
}
