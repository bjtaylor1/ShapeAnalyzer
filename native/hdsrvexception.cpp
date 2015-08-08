#include "hdsrvexception.h"

hdsrvexception::hdsrvexception(string msg) throw() : msg(msg){}
hdsrvexception::~hdsrvexception() throw() {}

const char* hdsrvexception::what() const throw()
{
  return msg.data();
}
