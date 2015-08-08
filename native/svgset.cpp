#ifdef TESTING
#include "svgset.h"
#include <sstream>

svgset::svgset() : minX(0x7fffffff), minY(0x7fffffff), maxX(-1), maxY(-1) {}

void svgset::write_to_svg(xml_node& parent) const
{
	int pWidth = 3000; int pHeight = 3000;
	double width = maxX - minX;
	double height = maxY - minY;
	double xScale = pWidth / width;
	double yScale = pHeight / height;
	double scale = min(xScale, yScale);
	for(vector<svgelement>::const_iterator element = elements.begin(); element != elements.end(); element++)
	{
		int i = 0;
		stringstream pathdata;
		for(vector<coord>::const_iterator coord = element->coords.coords.begin(); coord != element->coords.coords.end(); coord++)
		{
			if(i++ == 0) pathdata << "M"; else pathdata << " L";
			double x = scale * (coord->e - minX);
			double y = scale * (coord->n - minY);
			pathdata << x << "," << y;
		}
		xml_node pathnode = parent.append_child("path");
		pathnode.append_attribute("d") = pathdata.str().c_str();
		pathnode.append_attribute("style") = element->style.c_str();
	}
}

void svgset::add(const svgelement& element)
{
	elements.push_back(element);
	minX = min(minX, element.coords.minX);
	maxX = max(maxX, element.coords.maxX);
	minY = min(minY, element.coords.minY);
	maxY = max(maxY, element.coords.maxY);
}

#endif
