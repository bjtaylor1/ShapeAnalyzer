#ifndef CLASSHDSRVEXCEPTION
#define CLASSHDSRVEXCEPTION
#include <exception>
#include <string>

using namespace std;
class hdsrvexception : public std::exception
{
private:
  string msg;
  virtual const char* what() const throw();

public:
  hdsrvexception(string msg) throw();
  virtual ~hdsrvexception() throw();
};

#endif
