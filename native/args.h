#include <tclap/CmdLine.h>
#include <string>

using namespace std;
class args
{
public:
  static TCLAP::SwitchArg verbose;
  static TCLAP::ValueArg<int> port;
  static TCLAP::ValueArg<string> filesDir;
  static void addAll(TCLAP::CmdLine& cmdLine);
};
