#include <vector>
#include <fstream>
#include "contour.h"


class tile
{
public:
	tile(std::ifstream& file);

private:
	std::vector<contour> contours;
	
};
