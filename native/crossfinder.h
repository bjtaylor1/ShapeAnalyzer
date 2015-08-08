#include <vector>
#include <set>
#include "contour.h"
#include "cross.h"
#include <boost/filesystem.hpp>
#include "latlong.h"

typedef const vector<coord>::const_iterator PCOORD;
using namespace std;
namespace fs = boost::filesystem;

#ifdef TESTING
#include "svgset.h"
#include <src/pugixml.hpp>
using namespace pugi;
#endif

class crossfinder
{
public:

#ifdef TESTING
	static xml_node svgnode;
	static svgset svgs;
#endif
	
	static fs::path cacheroot;
	static int getmaxpercentage(const vector<latlong>& latlongs);
	static int getmaxpercentage(const vector<coord>& coords);
	static int getmaxpercentage(const set<contour>& contours, const vector<coord>& coords);
	static fs::path getcachefilename(PCOORD start, PCOORD end);
	static bool get_line_intersection(PCOORD tStart, PCOORD tEnd, PCOORD cStart, PCOORD cEnd, float* tProportion);
	static bool trygetcachedvalues(const string& cachefilename, vector<int>& crosses);
	static void cachevalues(const string& cachefilename, const vector<int>& crosses);
};
