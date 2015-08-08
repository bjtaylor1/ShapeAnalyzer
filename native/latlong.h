#pragma once
#include <fstream>

class latlong
{
public:
	latlong(int lat, int lon);
	latlong(double lat, double lon);
	latlong(std::istream& ifs);
	~latlong();
	int lat,lon;
  double getLatDouble() const;
  double getLonDouble() const;
};

