#include "latlong.h"

latlong::latlong(std::istream& str)
{
	str.read((char*)&lat, sizeof(int));
	str.read((char*)&lon, sizeof(int));
}

double latlong::getLatDouble() const
{
  return ((double)lat) / 10000;
}

double latlong::getLonDouble() const
{
  return ((double)lon) / 10000;
}

latlong::latlong(double lat, double lon) : lat((int)(lat * 10000)), lon((int)(lon * 10000)) {}

latlong::latlong(int lat, int lon) : lat(lat),lon(lon){}

latlong::~latlong(){}
