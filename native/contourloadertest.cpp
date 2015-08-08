#include <gtest/gtest.h>
#include "contourloader.h"
#include <vector>
#include "coordset.h"
#include <set>

using namespace std;

class contourloaderTest : public ::testing::Test
{
public:
	contourloader c;
};
/*
TEST_F(contourloaderTest, loadsandprunes)
{
	vector<coord> coordsv;
	coordsv.push_back(coord(500000, 500000));
	coordsv.push_back(coord(500006, 500006));
	coordset coords(coordsv);
	set<contour> contours;
	c.loadandprune(coords, contours);
	ASSERT_EQ(3, contours.size());	
}

*/


