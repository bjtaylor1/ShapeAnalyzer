#ifdef DONTTRUSTSMARTPTR

#include "socketwrapper.h"
#include <iostream>

int socketwrapper::numleft = 0;

socketwrapper::socketwrapper(boost::asio::io_service& ioservice)
{
  std::cout << "Creating a socket, there are now " << (++numleft) << std::endl;
  thesocket = new tcp::socket(ioservice);
}

socketwrapper::~socketwrapper()
{
  std::cout << "Destroying a socket, there are now " << (--numleft) << std::endl;
  delete thesocket;
}

#endif

