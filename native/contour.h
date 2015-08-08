#pragma once
#include <vector>
#include <fstream>
#include "coord.h"

#ifdef TESTING
#include <src/pugixml.hpp>
using namespace pugi;
#endif

using namespace std;

class contour
{
public:
  contour(int _height, int _minX, int _minY, int _maxX, int _maxY, std::vector<coord>& _coords);
	contour(std::ifstream& file);
	~contour();

	int height;
	int minX, minY, maxX, maxY;
  friend ostream& operator<<(ostream& os, const contour& obj);

	std::vector<coord> coords;
  std::vector<int> hashcode;
  void makehashcode();

#ifdef TESTING
	void add_svg_to(xml_node parent);
	string get_path() const;
#endif

};

bool operator<(const contour& lhs, const contour& rhs);
