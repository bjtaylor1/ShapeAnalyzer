#include "com_bjt_ShapeAnalyzer_App.h"
#include <vector>
#include "coord.h"
#include "latlong.h"
#include "crossfinder.h"

using namespace std;

JNIEXPORT jdouble JNICALL Java_com_bjt_ShapeAnalyzer_App_getmaxpercentage
  (JNIEnv * env, jclass theclass, jdoubleArray thearray)
{
	jsize size = env->GetArrayLength(thearray);
	vector<double> input(size);
	env->GetDoubleArrayRegion(thearray, 0, size, &input[0]);

	vector<latlong> latlongs;
	for(vector<double>::const_iterator it = input.begin(); it != input.end(); it++)
	{
		double lat = *it;
		it++;
		double lon = *it;
		latlong ll(lat,lon);
		latlongs.push_back(ll);
	}	
	return crossfinder::getmaxpercentage(latlongs);


}
