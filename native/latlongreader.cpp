#include "latlongreader.h"
#include <iostream>

bool latlongreader::read(std::vector<int>& input, std::vector<latlong>& latlongs)
{
  int inputcount =  input.size();
  if(inputcount % 2 != 0)
  {
    return false;
  }

  int latlongcount = inputcount / 2;
  std::vector<int>::iterator inputiterator = input.begin();
  for(int i = 0; i < latlongcount; i++)
  {
    int lat = *(inputiterator++);
    int lon = *(inputiterator++);
    latlongs.push_back(latlong(lat,lon));
  }
  return true;
}
