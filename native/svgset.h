#ifdef TESTING
#ifndef CLASSSVGSET
#define CLASSSVGSET

#include "svgelement.h"
#include <vector>
#include <src/pugixml.hpp>

using namespace std;
using namespace pugi;
class svgset
{
public:
	svgset();

	int minX, minY, maxX, maxY;
	vector<svgelement> elements;
	void write_to_svg(xml_node& parent) const;
	void add(const svgelement& element);
};

#endif
#endif
