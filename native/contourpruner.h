#ifndef CLASSCONTOURPRUNER
#define CLASSCONTOURPRUNER
#include <set>
#include "contour.h"
#include "coordset.h"
#include "contour.h"
#include <iostream>

class contourpruner
{
public:
	virtual set<contour> prunecontours(const coordset& coords, const set<contour>& contours) const = 0;
};

class gridcontourpruner : public contourpruner
{
public:
	virtual set<contour> prunecontours(const coordset& coords, const set<contour>& contours) const;
};

class corrcontourpruner : public contourpruner
{
public:
	virtual set<contour> prunecontours(const coordset& coords, const set<contour>& contours) const;
};


#endif
