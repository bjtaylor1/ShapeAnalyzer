#include "crossinfo.h"

crossinfo::crossinfo(float _order, int _height) : order(_order), height(_height){}

int operator<(const crossinfo& c1, const crossinfo& c2)
{
	return (c1.order < c2.order);
}
