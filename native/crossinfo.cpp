#include "crossinfo.h"

crossinfo::crossinfo(int _height, double _e, double _n, float _proportion) : height(_height), e(_e), n(_n), proportion(_proportion) {}

int operator<(const crossinfo& c1, const crossinfo& c2)
{
	return (c1.proportion < c2.proportion);
}

