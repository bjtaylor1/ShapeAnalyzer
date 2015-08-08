#include <cstdlib>
#include <iostream>
#include <tclap/CmdLine.h>
#include "args.h"
#include <exception>
#include "processor.h"

using namespace std;
int main(int argc, char* argv[])
{  
  try
  {
    TCLAP::CmdLine cmdLine("hdsrv");
    args::addAll(cmdLine);
    cmdLine.parse(argc, argv);
  }
  catch (TCLAP::ArgException &e)
  {
    cerr << "Error: " << e.error() << " for arg " << e.argId() << endl;
    return 1;
  }

	vector<int> inputs;
	int numInputs = 0;
	cin >> numInputs;
	int input = 0;
	for(int i = 0; i < numInputs; i++)
	{
		cin >> input;
		inputs.push_back(input);
	}

	vector<int> outputs;
	processor::process(inputs, outputs);
	if(args::verbose.getValue()) cout << "Done processing, there are " << outputs.size() << " outputs" << endl;
	for(vector<int>::const_iterator it = outputs.begin(); it != outputs.end(); it++)
	{
		cout << (*it) << endl;
	}
  return 0;
}
