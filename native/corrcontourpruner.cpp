#include "contourpruner.h"
#include <set>
#include "contour.h"
#include "coordset.h"
#include "iteratorpair.h"
#include <iostream>
using namespace std;

set<contour> corrcontourpruner::prunecontours(const coordset& coords, const set<contour>& contours) const
{
  set<contour> newcontours;
  vector<coordset> coordpairs;
  for(iteratorpair<vector<coord>::const_iterator> it(coords.coords.begin()); it.neitherIs(coords.coords.end()); it.increment())
  {
    vector<coord> coordpair(it.start, it.end);
    coordset cp(coordpair);
    coordpairs.push_back(cp);
  }
  for(set<contour>::iterator it = contours.begin(); it != contours.end(); it++)
  {
    if(coordset::mightoverlap(coordpairs, *it))
    {
      newcontours.insert(*it);
    }
  }
  return newcontours;
}
