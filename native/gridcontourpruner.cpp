#include "contourpruner.h"
#include <set>
#include "contour.h"
#include "coordset.h"
#include <iostream>

using namespace std;

set<contour> gridcontourpruner::prunecontours(const coordset& coords, const set<contour>& contours) const
{
	set<contour> newcontours;
	for(set<contour>::const_iterator it = contours.begin(); it != contours.end(); it++)
	{
		if(coords.mightoverlap(*it))
		{
			newcontours.insert(*it);
		}
	}  
	return newcontours;
}

