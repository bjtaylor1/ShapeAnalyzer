#include "stringtoints.h"

using namespace std;
void stringtoints::convert(string& s, vector<int>& ints)
{
  ints.push_back(s.length());
  for(string::iterator it = s.begin(); it != s.end(); it++)
  {
    int intval = (int)(*it);
    ints.push_back(intval);
  }
}

