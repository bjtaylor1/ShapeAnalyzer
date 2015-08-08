#ifndef CLASSGRIDFILESETDETERMINER
#define CLASSGRIDFILESETDETERMINER


#include "gridfiledeterminer.h"
#include <set>
#include <string>

class gridfilesetdeterminer
{
public:
  static void getfiles(coord& coord1, coord& coord2, std::set<std::string>& files) ;
  
};

#endif

