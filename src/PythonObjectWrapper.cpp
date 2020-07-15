#include "PythonObjectWrapper.h"


using namespace NCppPython;


// PythonObjectWrapper definations
PythonObjectWrapper::PythonObjectWrapper() : 
m_poPythonObject(NULL)
{
}

PythonObjectWrapper::PythonObjectWrapper(PyObject* poPythonObject) :
m_poPythonObject(poPythonObject)
{
}

PythonObjectWrapper::~PythonObjectWrapper()
{
	Release();
}

PyObject* PythonObjectWrapper::getObject()
{
	return m_poPythonObject;
}

PyObject* PythonObjectWrapper::setObject(PyObject* poPythonObject)
{
	return (m_poPythonObject = poPythonObject);
}

PyObject* PythonObjectWrapper::AddRef()
{
	Py_XINCREF(m_poPythonObject);
	return m_poPythonObject;
}

void PythonObjectWrapper::Release()
{
	Py_XDECREF(m_poPythonObject);
	m_poPythonObject = NULL;
}

PyObject* PythonObjectWrapper::operator ->()
{
	return m_poPythonObject;
}

bool PythonObjectWrapper::is()
{
	return m_poPythonObject ? true : false;
}

PythonObjectWrapper::operator PyObject*()
{
	return m_poPythonObject;
}

PyObject* PythonObjectWrapper::operator = (PyObject* poPythonObject)
{
	m_poPythonObject = poPythonObject;
	return m_poPythonObject;
}

PythonObjectWrapper::operator bool()
{
	return m_poPythonObject ? true : false;
}
