#include "coordset.h"
#include <algorithm>

coordset::coordset(const vector<coord>& _coords) : minX(-1), minY(-1), maxX(-1), maxY(-1), coords(_coords)
{
  for(vector<coord>::const_iterator it = coords.begin(); it != coords.end(); it++)
  {
    if(minX == -1 || it->e < minX) minX = it->e;
    if(minY == -1 || it->n < minY) minY = it->n;
    if(maxX == -1 || it->e > maxX) maxX = it->e;
    if(maxY == -1 || it->n > maxY) maxY = it->n;
  }
}

coordset::coordset(vector<coord>::const_iterator c1, vector<coord>::const_iterator c2, bool populate) : minX(-1), minY(-1), maxX(-1), maxY(-1)
{
	minX = min(c1->e, c2->e);
	maxX = max(c1->e, c2->e);
	minY = min(c1->n, c2->n);
	maxY = max(c1->n, c2->n);	
	if(populate)
	{
		coords.push_back(*c1);
		coords.push_back(*c2);
	}
}

coordset& coordset::operator=(const coordset& c)
{
  coords = c.coords;
  return *this;
}

bool coordset::mightoverlap(const contour& c) const
{
  return ! (maxX < c.minX || maxY < c.minY || minX > c.maxX || minY > c.maxY) ;
}

bool coordset::mightoverlap(const vector<coordset>& coordsets, const contour& c)
{
  for(vector<coordset>::const_iterator it = coordsets.begin(); it != coordsets.end(); it++)
  {
    if(it->mightoverlap(c)) return true;
  }
  return false;
}

