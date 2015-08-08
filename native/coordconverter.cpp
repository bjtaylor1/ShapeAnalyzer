#include "coordconverter.h"
#include <proj_api.h>
#include "hdsrvexception.h"
#include <iostream>
#include "args.h"

void coordconverter::convert(const std::vector<latlong>& latlongs, std::vector<coord>& coords)
{
  projPJ pjMerc = pj_init_plus("+proj=tmerc +lat_0=49 +lon_0=-2 +k=0.9996012717 +x_0=400000 +y_0=-100000 +ellps=airy +datum=OSGB36 +units=m +no_defs");
  if(pjMerc == NULL) throw hdsrvexception("pj_init_plus merc failed"); 

  projPJ pjLatLon = pj_init_plus("+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs");
  if(pjLatLon == NULL) 
	{
		pj_free(pjMerc);
		throw hdsrvexception("pj_init_plus proj failed");
	}

	  
  for(std::vector<latlong>::const_iterator it = latlongs.begin(); it != latlongs.end(); it++)
  {
    double x = it->getLonDouble() * DEG_TO_RAD;
    double y = it->getLatDouble() * DEG_TO_RAD;

    if(pj_transform(pjLatLon, pjMerc, 1, 1, &x, &y, NULL) != 0)
    {
			pj_free(pjMerc);
			pj_free(pjLatLon);
			throw hdsrvexception("pj_transform failed");
    }
    coord c;
    c.setNDouble(y);
    c.setEDouble(x);
    coords.push_back(c);
  }
  
  pj_free(pjMerc);
  pj_free(pjLatLon);

    
}
