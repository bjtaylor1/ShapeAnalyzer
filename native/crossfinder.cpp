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
#ifdef TESTING
#include <src/pugixml.hpp>
#include "svgset.h"
#include "testdata.h"

using namespace pugi;
xml_node crossfinder::svgnode;
svgset crossfinder::svgs;
#endif

using namespace std;
namespace fs = boost::filesystem;

fs::path crossfinder::cacheroot("cache");

int crossfinder::getclimbing(const vector<latlong>& latlongs)
{
	vector<coord> coords;
	coordconverter::convert(latlongs, coords);
	return getclimbing(coords);
}

int crossfinder::getclimbing(const vector<coord>& coords)
{
	contourloader cl;
	set<contour> contours;
	coordset cs(coords);
	cl.loadandprune(cs, contours);

#ifdef TESTING
	xml_document svgdoc;
	svgnode = svgdoc.append_child("svg");
	for(set<contour>::const_iterator contour = contours.begin(); contour != contours.end(); contour++)
	{
		svgs.add(svgelement(coordset(contour->coords), "stroke:#0000ff;fill:none;stroke-width:1"));
	}

	svgs.add(svgelement(coordset(coords), "stroke:#ff0000;fill:none;stroke-width:2"));
#endif	

	if(args::verbose.getValue()) cout << "finding crosses" << endl;
	int climbing = getclimbing(contours, coords);
	if(args::verbose.getValue()) cout << "found crosses" << endl;

#ifdef TESTING
	cout << "writing svg" << endl;
	svgs.write_to_svg(svgnode);
	svgdoc.save_file(testdata::filename.c_str());
	cout << "written svg" << endl;
#endif
	return climbing;
}

fs::path crossfinder::getcachefilename(PCOORD start, PCOORD end)
{
	stringstream ss;
	ss << start->e << "_" << start->n << "_" << end->e << end->n << ".cache";
	return fs::path(cacheroot / ss.str());
}

bool crossfinder::trygetcachedvalues(const string& cachefilename, vector<int>& crosses)
{
#ifdef TESTING
	return false;//otherwise it doesn't write the crosses to the svg
#endif

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

int crossfinder::getclimbing(const set<contour>& contours, const vector<coord>& coords)
{
	vector<int> crosses;
	gridcontourpruner gcp;

	//loop through coords
	int cachehits = 0, cachemisses = 0;
	for(iteratorpair<vector<coord>::const_iterator> coord_it = coords.begin(); coord_it.neitherIs(coords.end()); coord_it.increment())
	{
		vector<int> thissegmentscrosses;
		string cachefilename = getcachefilename(coord_it.start, coord_it.end).string();
		if(trygetcachedvalues(cachefilename, thissegmentscrosses))
		{
			cachehits++;

		}
		else
		{
			cachemisses++;


			vector<crossinfo> crossinfos;//the crosses that have been found

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
						int height = contour_it->height;
						crossinfo c(tProportion, height);
						crossinfos.push_back(c);

#ifdef TESTING
						svgs.add(svgelement(coordset(coord_it.start, coord_it.end, true), "stroke:#000000;fill:none;stroke-width:2"));
#endif					
					}
				}	
			}

			sort(crossinfos.begin(), crossinfos.end());
			for(vector<crossinfo>::const_iterator crossinfo_it = crossinfos.begin(); crossinfo_it != crossinfos.end(); crossinfo_it++)
			{
				thissegmentscrosses.push_back(crossinfo_it->height);
			}

			cachevalues(cachefilename, thissegmentscrosses);
		} //if cached
		crosses.insert(crosses.end(), thissegmentscrosses.begin(), thissegmentscrosses.end());
	}	

	int heightdiff = 0;
	if(crosses.size() > 0)
	{
		int startheight = *(crosses.begin());
		int endheight = (crosses.back());
		heightdiff = endheight - startheight;
	}

#ifdef TESTING
	const int NULL_HEIGHT =       0x80000000
	int lastheight = NULL_HEIGHT;
	int flats = 0;
	for(vector<int>::const_iterator it = crosses.begin(); it != crosses.end(); it++)
	{
		if((*it) == lastheight)
		{
			flats++;
			double perflat = 10;
			if((*it) < 300) perflat = (int)(((double)10) * (*it) / 300);
			cout << perflat << " ";
			climbingonflats += perflat;
		}
		lastheight = *it;
	}

	{
	ofstream outputfile;
	outputfile.open("ridesdata.csv", ios_base::app);
	outputfile << crosses.size() << "," << flats << "," << climbingonflats << "," << startheight << "," << endheight << endl;
	outputfile.close();
	}

#endif
	int totalclimbing = (crosses.size() * 10 / 2) + heightdiff;
	return totalclimbing;
}

bool crossfinder::get_line_intersection(PCOORD tStart, PCOORD tEnd, PCOORD cStart, PCOORD cEnd, float* tProportion)
{
	float s1_x = (float)tEnd->e - tStart->e,     s1_y = (float)tEnd->n - tStart->n;
	float s2_x = (float)cEnd->e - cStart->e,     s2_y = (float)cEnd->n - cStart->n;

	float s = (-s1_y * (tStart->e - cStart->e) + s1_x * (tStart->n - cStart->n)) / (-s2_x * s1_y + s1_x * s2_y);
	*tProportion = ( s2_x * (tStart->n - cStart->n) - s2_y * (tStart->e - cStart->e)) / (-s2_x * s1_y + s1_x * s2_y);

	return (s >= 0 && s < 1 && *tProportion >= 0 && *tProportion < 1);
}
