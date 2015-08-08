#include "contour.h"
#include <set>

using namespace std;

class contourwriter
{
public:
	static void writecontours(const set<contour>& contours, const string name);
};
