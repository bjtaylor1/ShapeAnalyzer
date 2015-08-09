#include "contourloader.h"
#include "gridfilesetdeterminer.h"
#include "iteratorpair.h"
#include <boost/filesystem.hpp>
#include <vector>
#include "args.h"
#include "contour.h"
#include "contourpruner.h"
#include "hdsrvexception.h"

using namespace std;
using namespace boost;
namespace fs = boost::filesystem;

contourloader::contourloader()
{
	contourpruners.push_back(shared_ptr<contourpruner>(new gridcontourpruner()));
	contourpruners.push_back(shared_ptr<contourpruner>(new corrcontourpruner()));
}

void contourloader::loadcontours(const coordset& coords, set<contour>& contours) const 
{
	set<string> files;

	for(iteratorpair<vector<coord>::const_iterator> it(coords.coords.begin()); it.neitherIs(coords.coords.end()); it.increment())
	{
		coord c1 = *it.start;
		coord c2 = *it.end;
		gridfilesetdeterminer::getfiles(c1, c2, files);
	}
	loadcontours(files, contours);
}

void contourloader::prunecontours(const coordset& coords, set<contour>& contours) const
{
	for(vector<shared_ptr<contourpruner> >::const_iterator pruner = contourpruners.begin(); pruner != contourpruners.end(); pruner++)
	{
		contours = (*pruner)->prunecontours(coords, contours);
	}
}

void contourloader::loadandprune(const coordset& coords, set<contour>& contours) const
{
	loadcontours(coords, contours);
	prunecontours(coords, contours);
}

void contourloader::loadcontours(const set<string>& files, set<contour>& contours) const
{
	fs::path baseDir("/home/ben/terraindata");
	if(args::verbose.getValue()) cout << "Got " << files.size() << " files" << endl;
	for(set<string>::iterator i = files.begin(); i != files.end(); i++)
	{
		fs::path fileName( (*i) + ".gml.dat");
		fs::path filePath = baseDir / fileName;
		ifstream file(filePath.string().c_str());
		if(!file.is_open()) throw hdsrvexception("could not open file " + filePath.string());
		int numContours;
		file.read((char*)&numContours, sizeof(int));
		for(int i = 0; i < numContours; i++)
		{
			const contour c(file);
			contours.insert(c);
		}
	}
}

