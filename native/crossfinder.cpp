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

double crossfinder::getmaxpercentage(const vector<latlong>& latlongs)
{
	vector<coord> coords;
	coordconverter::convert(latlongs, coords);
	cout << "got " << coords.size() << " coords" << endl;
	for(vector<coord>::const_iterator it = coords.begin(); it != coords.end(); it++)
	{
		cout << " coord: " << it->getEDouble() << "," << it->getNDouble() << endl;
	}
	return getmaxpercentage(coords);
}

double crossfinder::getmaxpercentage(const vector<coord>& coords)
{
	contourloader cl;
	set<contour> contours;
	coordset cs(coords);
	cl.loadandprune(cs, contours);

	double maxpercentage = getmaxpercentage(contours, coords);
	return maxpercentage;
}


double crossfinder::getmaxpercentage(const set<contour>& contours, const vector<coord>& coords)
{
	gridcontourpruner gcp;

	//loop through coords
	int pointnum = -1;
	vector<crossinfo> crossinfos;
	for(iteratorpair<vector<coord>::const_iterator> coord_it = coords.begin(); coord_it.neitherIs(coords.end()); coord_it.increment())
	{
		++pointnum;
		coordset trackdelta(coord_it.start, coord_it.end, false);
		set<contour> relevantcontours = gcp.prunecontours(trackdelta, contours);

		//loop through contours
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
					double deltae = coord_it.end->getEDouble() - coord_it.start->getEDouble();
					double deltan = coord_it.end->getNDouble() - coord_it.start->getNDouble();
					double e = coord_it.start->getEDouble() + (tProportion * deltae);
					double n = coord_it.start->getNDouble() + (tProportion * deltan);
					cout << pointnum << ": " << tProportion << " along " << (*(coord_it.start)) << " to " << (*(coord_it.end)) << " = " << e << "," << n << endl;
					crossinfo cross(contour_it->height, e, n, pointnum + tProportion);//tProportion should always be 0-1, add (int) pointnum gives overall proportion
					crossinfos.push_back(cross);
				}
			}	

		}

	}	

	sort(crossinfos.begin(), crossinfos.end());
	double maxpercentage = 0;
	for(iteratorpair<vector<crossinfo>::iterator> it = crossinfos.begin(); it.neitherIs(crossinfos.end()); it.increment())
	{
		double deltae = it.end->e - it.start->e;
		double deltan = it.end->n - it.start->n;
		double dist = sqrt(pow(deltan,2) + pow(deltae,2));
		double heightdiff = abs(it.end->height - it.start->height);
		double percentage = heightdiff/dist;
		cout << "rises/falls " << heightdiff << " in " << dist << "m from " << it.start->e<< "," <<it.start->n << " to " << it.end->e << "," << it.end->n << " = " << percentage << endl;
		if(percentage > maxpercentage) maxpercentage = percentage;
	}
	
	return maxpercentage;
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
