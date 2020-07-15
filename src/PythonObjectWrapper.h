#ifndef PYTHON_OBJECT_WRAPPER_H
#define PYTHON_OBJECT_WRAPPER_H

#include <Python.h>


namespace NCppPython
{
	class PythonObjectWrapper
	{
		public:
			PythonObjectWrapper();

			PythonObjectWrapper(PyObject* poPythonObject);

			~PythonObjectWrapper();

			PyObject* getObject();

			PyObject* setObject(PyObject* poPythonObject);

			PyObject* AddRef();

			void Release();

			PyObject* operator ->();

			bool is();
			
			operator PyObject*();

			PyObject* operator = (PyObject* poPythonObject);

			operator bool();
			
		private:
			PyObject *m_poPythonObject;
	};
};


#endif // PYTHON_OBJECT_WRAPPER_H
