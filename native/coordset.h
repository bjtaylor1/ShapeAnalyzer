#ifndef CLASSCOORDSET
#define CLASSCOORDSET
#include <vector>
#include "coord.h"
#include "contour.h"

using namespace std;
class coordset
{
public:
  int minX, minY, maxX, maxY;
  vector<coord> coords;
	
	coordset(const vector<coord>& _coords);
	coordset(vector<coord>::const_iterator c1, vector<coord>::const_iterator c2, bool populate);
  coordset& operator=(const coordset&);
  bool mightoverlap(const contour& c) const;
  static bool mightoverlap(const vector<coordset>& coordsets, const contour& c);
};


#endif
