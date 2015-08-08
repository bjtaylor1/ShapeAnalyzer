#include <gtest/gtest.h>
#include <vector>
#include <set>
#include "contourloader.h"
#include "contour.h"
#include "coordset.h"

class contourprunerTest : public ::testing::Test
{
public:
	gridcontourpruner g;
	corrcontourpruner c;
	contourloader l;
};

TEST_F(contourprunerTest, gridDoesntPruneOutStuffInItsBox)
{
	vector<coord> coordsv;
	coordsv.push_back(coord(500000,500000));
	coordsv.push_back(coord(500006,500006));
	coordset coords(coordsv);
	set<contour> contours;

	l.loadcontours(coords, contours);
	ASSERT_EQ(5, contours.size());

	contours = g.prunecontours(coords, contours);
	ASSERT_EQ(4, contours.size());
}


TEST_F(contourprunerTest, gridPrunesStuffOutOfItsBox)
{
	vector<coord> coordsv;
	coordsv.push_back(coord(500000,500000));
	coordsv.push_back(coord(500004,500004));
	coordset coords(coordsv);
	set<contour> contours;

	l.loadcontours(coords, contours);
	ASSERT_EQ(5, contours.size());

	contours = g.prunecontours(coords, contours);
	ASSERT_EQ(3, contours.size());
}


TEST_F(contourprunerTest, corrPrunesStuffInGridsBox)
{
	vector<coord> coordsv;
	coordsv.push_back(coord(500000,500000));
	coordsv.push_back(coord(500006,500006)); //long line, grid would not prune out 500, but corr should
	coordset coords(coordsv);
	set<contour> contours;

	l.loadcontours(coords, contours);
	ASSERT_EQ(5, contours.size());

	contours = c.prunecontours(coords, contours);
	ASSERT_EQ(3, contours.size());
}


