#include "CppPythonException.h"


using namespace NCppPython;


CppPythonException::CppPythonException() :
				m_constErrorString("")
{
}

CppPythonException::CppPythonException(const char* constErrorString) :
				m_constErrorString(constErrorString)
{
}

CppPythonException::~CppPythonException() throw ()
{
}

const char* CppPythonException::what () const throw ()
{
	return m_constErrorString;
}
