#pragma once
#include <fstream>

using namespace std;

class coord
{

public:
	int e, n;
  coord();
	coord(int e, int n);
	coord(std::ifstream& ifs);
	~coord();

  double getEDouble() const;
  double getNDouble() const;
  double getcomparator() const;
  void setEDouble(double _e);
  void setNDouble(double _n);

  friend ostream& operator<<(ostream& os, const coord& c);
};

bool operator<(const coord& lhs, const coord& rhs);

