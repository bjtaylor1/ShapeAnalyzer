#include <vector>
#include "latlong.h"

class latlongreader
{
public:
  static bool read(std::vector<int>& input, std::vector<latlong>& latlongs);
};
