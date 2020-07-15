#include <Python.h>
#include "PythonInterpreter.h"


using namespace NCppPython;


PythonInterpreter::PythonInterpreter()
{
}

PythonInterpreter::~PythonInterpreter()
{
}

void PythonInterpreter::initializeInterpreter()
{
	Py_Initialize();
	// To Do : Need to remove these. Set python path using env variables.
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('/home/local/bin')");
}

void PythonInterpreter::finalizeInterpreter()
{
	Py_Finalize();
}





