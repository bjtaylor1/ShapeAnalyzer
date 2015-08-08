#include "args.h"

TCLAP::SwitchArg args::verbose("v", "verbose", "Whether to print output");
TCLAP::ValueArg<string> args::filesDir("d", "filesDir", "Directory in which data files are", true, "", "filesDir");

void args::addAll(TCLAP::CmdLine& cmdLine)
{
  cmdLine.add(verbose);
  cmdLine.add(filesDir);

}


