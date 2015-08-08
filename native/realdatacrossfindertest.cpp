#include <gtest/gtest.h>
#include <src/pugixml.hpp>
#include <iostream>
#include "latlong.h"
#include "coordconverter.h"
#include <string>
#include "crossfinder.h"
#include "testdata.h"
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <ctime>

using namespace pugi;
using namespace std;
using namespace boost;
namespace fs = boost::filesystem;

void testfile(const char* gpxFileName)
{
	testdata::filename = string(gpxFileName).append(".svg");

	xml_document doc;
	xml_parse_result result = doc.load_file(gpxFileName);
	//ASSERT_EQ(status_ok, result.status);
	xpath_node_set trkpts = doc.select_nodes("gpx/trk/trkseg/trkpt");
	//ASSERT_GT(trkpts.size(), 0);
	vector<latlong> latlongs;
	int i = 0;
	cout << "Reading " << gpxFileName << endl;
	for(xpath_node_set::const_iterator it = trkpts.begin(); it != trkpts.end() ; it++)
	{
		double lat = it->node().attribute("lat").as_double();
		double lon = it->node().attribute("lon").as_double();
		latlongs.push_back(latlong(lat, lon));
	}
	cout << "Read " << latlongs.size() << " latlongs" << endl;

	double start = (double)clock();	
	int climbing = crossfinder::getclimbing(latlongs);
	double end = (double)clock();
	cout << gpxFileName << " : " << climbing << ", took " << (1000 * (end - start) / CLOCKS_PER_SEC) << "ms" << endl;
}

TEST(realdatacrossfinderTest, allFiles)
{
	fs::directory_iterator end;
	regex filter(".*\\.gpx");

	{
	ofstream ridesdata;
	ridesdata.open("ridesdata.csv", ios_base::trunc);
	ridesdata << "Name,Crosses,Flats,Climbing On Flats,Start Height,End Height" << endl;
	ridesdata.close();
	}

	for(fs::directory_iterator i("."); i != end; ++i)
	{
		if(fs::is_regular_file(i->status()))
		{
			smatch match;
			if(regex_match(i->path().filename().string(), match, filter))
			{
				cout << "=======================================" << endl << "TESTING FILE: " << i->path() << endl;

				{
				ofstream ridesdata;
				ridesdata.open("ridesdata.csv", ios_base::app);
				ridesdata << i->path() << ",";
				ridesdata.close();
				}

				testfile(i->path().filename().string().c_str());
				cout << endl;
			}
		}
	}
}

