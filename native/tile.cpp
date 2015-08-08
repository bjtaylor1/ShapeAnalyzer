#include "tile.h"

#include <fstream>

tile::tile(std::ifstream& file) : contours()
{
	int contourCount = 0;
	file.read((char*)&contourCount, 4);
	for(int i = 0; i < contourCount; i++)
	{
		contour c(file);
		contours.push_back(c);
	}
}