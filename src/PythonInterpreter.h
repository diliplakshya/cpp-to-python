#ifndef PYTHON_INTERPRETER_H
#define PYTHON_INTERPRETER_H


namespace NCppPython
{
	class PythonInterpreter
	{
		public:
		   static void initializeInterpreter();
		   static void finalizeInterpreter();

		private:
		   PythonInterpreter();  // Private so that it can  not be called
		   ~PythonInterpreter();
		   PythonInterpreter(PythonInterpreter const&);             // copy constructor is private
		   PythonInterpreter& operator=(PythonInterpreter const&);  // assignment operator is private
	};
};


#endif // PYTHON_INTERPRETER_H

