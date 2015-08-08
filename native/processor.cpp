#include "processor.h"
#include "coordconverter.h"
#include "gridfiledeterminer.h"
#include <iostream>
#include "crossfinder.h"
#include "latlong.h"
#include "iteratorpair.h"
#include "args.h"

using namespace std;

void processor::process(const vector<int>& input, vector<int>& output)
{
	vector<latlong> latlongs;
	if(args::verbose.getValue()) cout << "Processing " << input.size() << " ints" << endl;

	for(iteratorpair<vector<int>::const_iterator> it(input.begin()); it.neitherIs(input.end()); it.incrementTwice())
	{
		int lat = *(it.start);
		int lon = *(it.end);

		latlong ll(lat,lon);
		latlongs.push_back(ll);
	}
	int climbing = crossfinder::getclimbing(latlongs);
	if(args::verbose.getValue()) cout << "Result = " << climbing << endl;
	output.push_back(climbing);
}
