#include "filefuncs.h"
#include "args.h"
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

using namespace boost;
namespace fs = boost::filesystem;

void filefuncs::checkfiles()
{
  regex filter(".*\\.gml\\.dat");
  cout << "Using files from " << args::filesDir.getValue() << ":" << endl;  
  fs::directory_iterator end;
  for(fs::directory_iterator i(args::filesDir.getValue()); i != end; ++i)
  {
    if(fs::is_regular_file(i->status()))
    {
      smatch match;
      if(regex_match(i->path().filename().string(), match, filter))
      {
        cout << i->path().filename().string() << endl;
      }
    }
  }

  fs::path basedir(args::filesDir.getValue());
  fs::path file("TT00.gml.dat");
  fs::path filePath = basedir / file;
  cout << "using: " << filePath.string() << endl;  
}
