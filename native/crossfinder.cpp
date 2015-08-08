#include "crossfinder.h"
#include "iteratorpair.h"
#include "crossinfo.h"
#include <algorithm>
#include "contourloader.h"
#include "contourpruner.h"
#include "args.h"
#include <boost/filesystem.hpp>
#include <iostream>
#include "coordconverter.h"
#include <cmath>
#include <climits>

using namespace std;
namespace fs = boost::filesystem;

fs::path crossfinder::cacheroot("cache");

int crossfinder::getmaxpercentage(const vector<latlong>& latlongs)
{
	vector<coord> coords;
	coordconverter::convert(latlongs, coords);
	return getmaxpercentage(coords);
}

int crossfinder::getmaxpercentage(const vector<coord>& coords)
{
	contourloader cl;
	set<contour> contours;
	coordset cs(coords);
	cl.loadandprune(cs, contours);

	for(vector<coord>::const_iterator c_it = coords.begin(); c_it != coords.end(); c_it++)
	{

	}
	int climbing = getmaxpercentage(contours, coords);
	return climbing;
}


int crossfinder::getmaxpercentage(const set<contour>& contours, const vector<coord>& coords)
{
	vector<int> crosses;
	gridcontourpruner gcp;

	//loop through coords
	int maxpercentage = 0;
	for(iteratorpair<vector<coord>::const_iterator> coord_it = coords.begin(); coord_it.neitherIs(coords.end()); coord_it.increment())
	{
		coordset trackdelta(coord_it.start, coord_it.end, false);
		set<contour> relevantcontours = gcp.prunecontours(trackdelta, contours);

		//loop through contours
		double maxheight = LONG_MIN;
		double minheight =  LONG_MAX;
		for(set<contour>::const_iterator contour_it = relevantcontours.begin(); contour_it != relevantcontours.end(); contour_it++)
		{

			//loop through coords of THIS contour
			for(iteratorpair<vector<coord>::const_iterator> contour_coord_it = contour_it->coords.begin();
					contour_coord_it.neitherIs(contour_it->coords.end());
					contour_coord_it.increment())
			{
				float tProportion;
				if(get_line_intersection(coord_it.start, coord_it.end, contour_coord_it.start, contour_coord_it.end, &tProportion))
				{
					int height = contour_it->height;
					if(height > maxheight) maxheight = height;
					if(height < minheight) minheight = height;
				}
			}	

		}
		double deltax = coord_it.start->getEDouble() - coord_it.end->getEDouble();
		double deltay = coord_it.start->getNDouble() - coord_it.end->getNDouble();
		double dist = sqrt(pow(deltax,2) + pow(deltay,2));
		double percentage = 0;
		if(maxheight != INT_MAX && minheight != INT_MAX)
		{
			percentage = (maxheight - minheight) / dist;
		}
		if(percentage > maxpercentage)
		{
			maxpercentage = percentage;
		}

	}	

	return (int)floor(maxpercentage);
}

bool crossfinder::get_line_intersection(PCOORD tStart, PCOORD tEnd, PCOORD cStart, PCOORD cEnd, float* tProportion)
{
	float s1_x = (float)tEnd->e - tStart->e,     s1_y = (float)tEnd->n - tStart->n;
	float s2_x = (float)cEnd->e - cStart->e,     s2_y = (float)cEnd->n - cStart->n;

	float s = (-s1_y * (tStart->e - cStart->e) + s1_x * (tStart->n - cStart->n)) / (-s2_x * s1_y + s1_x * s2_y);
	*tProportion = ( s2_x * (tStart->n - cStart->n) - s2_y * (tStart->e - cStart->e)) / (-s2_x * s1_y + s1_x * s2_y);

	return (s >= 0 && s < 1 && *tProportion >= 0 && *tProportion < 1);
}

fs::path crossfinder::getcachefilename(PCOORD start, PCOORD end)
{
	stringstream ss;
	ss << start->e << "_" << start->n << "_" << end->e << end->n << ".cache";
	return fs::path(cacheroot / ss.str());
}

bool crossfinder::trygetcachedvalues(const string& cachefilename, vector<int>& crosses)
{
	if(fs::exists(cachefilename))
	{
		ifstream cachefile(cachefilename.c_str());
		if(cachefile.is_open())
		{
			int numcrosses = 0;
			cachefile.read((char*)&numcrosses, sizeof(int));
			for(int i = 0; i < numcrosses; i++)
			{
				int crossheight;
				cachefile.read((char*)&crossheight, sizeof(int));
				crosses.push_back(crossheight);
			}
			cachefile.close();
			return true;
		}
	}
	return false;
}

void crossfinder::cachevalues(const string& cachefilename, const vector<int>& crosses)
{
	ofstream cachefile(cachefilename.c_str());
	int size = crosses.size();
	cachefile.write((char*)&size, sizeof(int));
	for(vector<int>::const_iterator it = crosses.begin(); it != crosses.end(); it++)
	{
		int height = *it;
		cachefile.write((char*)&height, sizeof(int));
	}
	cachefile.close();
}
