#include <boost/asio.hpp>

using boost::asio::ip::tcp;

#ifdef DONTTRUSTSMARTPTR

class socketwrapper
{
public:
  tcp::socket* thesocket;
  socketwrapper(boost::asio::io_service& ioservice);
  ~socketwrapper();
private:
  static int numleft;
};

typedef boost::shared_ptr<socketwrapper> socket_ptr;
typedef socketwrapper SOCKETTYPE;
#define THESOCKET(s) (s->thesocket)

#else

typedef boost::shared_ptr<tcp::socket> socket_ptr;
typedef tcp::socket SOCKETTYPE;
#define THESOCKET(s) (s)

#endif
