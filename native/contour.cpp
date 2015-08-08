#include "contour.h"
#include "iteratorpair.h"
#include <iostream>
#include "utils.h"

#ifdef TESTING
#include <sstream>
void contour::add_svg_to(xml_node parent)
{
	xml_node path = parent.child("path");
	

}
string contour::get_path() const
{
	stringstream ss;
	int i = 0;
	for(vector<coord>::const_iterator coord = coords.begin(); coord != coords.end(); coord++)
	{
		if(i++ == 0)
		{
			ss << "M";
		}
		else
		{
			ss << "L";
		}
		ss << coord->e << " " << coord->n << " ";
	}
	return ss.str();
}
#endif

void contour::makehashcode()
{
	hashcode.push_back(minX);
	hashcode.push_back(maxX);
	hashcode.push_back(minY);
	hashcode.push_back(maxY);
	hashcode.push_back(height);
	for(vector<coord>::iterator it = coords.begin(); it != coords.end(); it++)
	{
		hashcode.push_back(it->e);
		hashcode.push_back(it->n);
	}
}

contour::contour(int _height, int _minX, int _minY, int _maxX, int _maxY, std::vector<coord>& _coords) : 
	height(_height), minX(_minX), minY(_minY), maxX(_maxX), maxY(_maxY), coords(_coords)
{
	makehashcode();
}

contour::contour(std::ifstream& file) : coords()
{
	file.read((char*)&height, sizeof(int));
	file.read((char*)&minX,sizeof(int));
	file.read((char*)&minY,sizeof(int));
	file.read((char*)&maxX,sizeof(int));
	file.read((char*)&maxY,sizeof(int));
	int coordCount = 0;
	file.read((char*)&coordCount, sizeof(int));
	for(int i = 0; i < coordCount; i++)
	{
		coord c(file);
		coords.push_back(c);
	}

	makehashcode();
}

ostream& operator<<(ostream& os, const contour& c)
{
	os << c.height << " " << c.coords;
	return os;
}

bool operator<(const contour& lhs, const contour& rhs)
{
	return lhs.hashcode < rhs.hashcode;
}

contour::~contour(){}
