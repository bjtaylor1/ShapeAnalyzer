#ifdef TESTING
#ifndef CLASSSVGELEMENT
#define CLASSSVGELEMENT

#include "coordset.h"
#include <string>
using namespace std;

class svgelement
{
public:
	svgelement(const coordset coords, const string style);
	coordset coords;
	string style;
};

#endif
#endif
