#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "gridfiledeterminer.h"
#include "latlong.h"
#include "coord.h"
#include "coordconverter.h"
#include "args.h"

using namespace std;

class gridfiledeterminerTest : public ::testing::Test
{
public:
	gridfiledeterminer g;
};

TEST_F(gridfiledeterminerTest, SO)
{
	double lat = 52.058516;
  double lon = -2.293112;
	latlong ll(lat, lon);
	vector<latlong> latlongs;
	latlongs.push_back(ll);
	vector<coord> coords;
	coordconverter::convert(latlongs, coords);
	ASSERT_EQ(1, coords.size());
	string gridfile = g.getfile(*coords.begin());
	ASSERT_EQ("SO84", gridfile);
}


TEST_F(gridfiledeterminerTest, SK)
{
	double lat = 53.221358;
  double lon = -0.754647;
	latlong ll(lat, lon);
	vector<latlong> latlongs;
	latlongs.push_back(ll);
	vector<coord> coords;
	coordconverter::convert(latlongs, coords);
	ASSERT_EQ(1, coords.size());
	string gridfile = g.getfile(*coords.begin());
	ASSERT_EQ("SK87", gridfile);
}

TEST_F(gridfiledeterminerTest, TT)
{
	coord testcoord(500000,500000);
	string gridfile = g.getfile(testcoord);
	ASSERT_EQ("TT00", gridfile);
}
