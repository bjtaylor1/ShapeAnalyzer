#include <algorithm>
#include "gridfilesetdeterminer.h"
#include "args.h"

using namespace std;

void gridfilesetdeterminer::getfiles(coord& coord1, coord& coord2, set<string>& files)
{
  coord coord3(coord1.getEDouble(), coord2.getNDouble());
  coord coord4(coord2.getEDouble(), coord1.getNDouble());
  string f1, f2, f3, f4;
  files.insert(gridfiledeterminer::getfile(coord1));
  files.insert(gridfiledeterminer::getfile(coord2));
  files.insert(gridfiledeterminer::getfile(coord3));
  files.insert(gridfiledeterminer::getfile(coord4));
}

