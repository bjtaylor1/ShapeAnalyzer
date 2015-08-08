#include "contourwriter.h"
#include <iostream>
#include <fstream>
#include "testdata.h"

void contourwriter::writecontours(const set<contour>& contours, const string name)
{
	ofstream file;
	file.open(testdata::filename.c_str());
	for(set<contour>::const_iterator contour = contours.begin(); contour != contours.end(); contour++)
	{
		int i = 0;
		for(vector<coord>::const_iterator coord = contour->coords.begin(); coord != contour->coords.end(); coord++)
		{
			if(i++ == 0)
			{
				file << "M ";
			}
			else
			{
				file << "L ";
			}
			file << coord->e << " " << coord->n << " ";
		}
	}
	file.close();

}
