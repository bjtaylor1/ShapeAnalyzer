#include "coord.h"
#include "latlong.h"
#include <vector>

class coordconverter
{
public:
  static void convert(const std::vector<latlong>& latlongs, std::vector<coord>& coords);
};
