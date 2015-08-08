#include "gridfiledeterminer.h"
#include <sstream>
#include <iostream>
#include "args.h"
#include "hdsrvexception.h"

using namespace std;

string gridfiledeterminer::getfile(coord& coord)
{
  int xindex = coord.e / 1000000;
  int yindex = coord.n / 1000000;
  string squares[13][7] = {
    {"SV", "SW", "SX", "SY", "SZ", "TV", ""},
    {""  , "SR", "SS", "ST", "SU", "TQ", "TR"},
    {""  , "SM", "SN", "SO", "SP", "TL", "TM"},
    {""  , ""  , "SH", "SJ", "SK", "TF", "TG"},
    {""  , ""  , "SC", "SD", "SE", "TA", ""},
    {""  , "NW", "NX", "NY", "NZ", "TT"  , ""}, //TT is testdata
    {""  , "NR", "NS", "NT", "NU", ""  , ""},
    {"NL", "NM", "NN", "NO", ""  , ""  , ""},
    {"NF", "NG", "NH", "NJ", "NK", ""  , ""},
    {"NA", "NB", "NC", "ND", ""  , ""  , ""},
    {""  , "HW", "HX", "HY", "HZ", ""  , ""},
    {""  , ""  , ""  , "HT", "HU", ""  , ""},
    {""  , ""  , ""  , ""  , "HP", ""  , ""}
  };
  if(xindex < 0 || xindex > 6) throw hdsrvexception("xindex is not within range");
  if(yindex < 0 || yindex > 12) throw hdsrvexception("yindex is not within range");
  string square = squares[yindex][xindex];
  if(square.size() == 0) throw hdsrvexception("Square size is zero");

  int xrem = (coord.e - (xindex * 1000000)) / 100000;
  int yrem = (coord.n - (yindex * 1000000)) / 100000;  

  stringstream ss;
  ss << square << xrem << yrem;

  return ss.str();

}
