#include "contour.h"
#include "gridfilesetdeterminer.h"
#include <vector>
#include "coordset.h"
#include <boost/shared_ptr.hpp>
#include "contourpruner.h"

using namespace std;
using namespace boost;

class contourloader
{
private:
	vector<shared_ptr<contourpruner> > contourpruners;
public:
  void loadcontours(const coordset& coords, set<contour>& contours) const;
	void prunecontours(const coordset& coords, set<contour>& contours) const; //will eventually have 'loadandprune'
	void loadandprune(const coordset& coords, set<contour>& contours) const;
  void loadcontours(const set<string>& files, set<contour>& contours) const ;
	contourloader();

};

