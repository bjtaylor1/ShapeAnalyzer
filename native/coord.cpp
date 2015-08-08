#include "coord.h"

coord::coord(ifstream& file)
{
	file.read((char*)&e, sizeof(int));
	file.read((char*)&n, sizeof(int));
}

double coord::getEDouble() const
{
  return e / 10;
}

double coord::getNDouble() const
{
  return n / 10;
}

void coord::setEDouble(double _e)
{
  e = _e * 10;
}

void coord::setNDouble(double _n)
{
  n = _n * 10;
}


coord::coord() : e(0), n(0) {}

coord::coord(int _e, int _n) : e(_e * 10), n(_n * 10){}

ostream& operator<<(ostream& os, const coord& c)
{
  os << "e=" << c.e << ",n=" << c.n;
  return os;
}

double coord::getcomparator() const
{
  //n is more significant...
  return ((double)n * 10000000) + e;//should only need 7 million but use 10 to be sure
}

bool operator<(const coord& lhs, const coord& rhs)
{
  return lhs.getcomparator() < rhs.getcomparator();
}

coord::~coord(){}
