#include <iostream>
using namespace std;

class crossinfo
{
public:
	int height;
	double e;
	double n;
	float proportion;
	crossinfo(int _height, double _e, double _n, float _proportion);
};

int operator<(const crossinfo& c1, const crossinfo& c2);

