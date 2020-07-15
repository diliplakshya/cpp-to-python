////////////////////////////////////////////////////////////////////////////////
//
//                DILIP KUMAR SHARMA CONFIDENTIAL & PROPRIETARY
//				--------------------------------------------
// 	Project : Interface module for Cpp to Python 
// 
// 
// 
// 
// 
//
////////////////////////////////////////////////////////////////////////////////

/***
 * @file CppPythonException.h
 * @author Dilip Kumar Sharma
 * @brief Custom exception class
 * @copyright Dilip Kumar Sharma
 * @date 29th April 2019
 ***/
 
/**
 *
 * @section General description
 *
 * This CppPythonException class is custom exception class used for LWT.
 *
 * @section Usage
 *
 * Call this class to throw and catch custom error messages exception.
 * 
 * 
 * Usage scenario:
 *
 * Throwing and catching custom error messages.
 *
 * @section input
 *
 * CppPythonException class does not take any input.
 *
 * @section Compatibility
 *
 * The CppPythonException code is writtern in C++ and is not cross platform compatible.
 *
 * @section Testing
 *
 * Tested on Ubuntu 12.04 LTS
 **/
 
////////////////////////////////////////////////////////////////////////////////

#ifndef CPP_PYTHON_EXCEPTION_H
#define CPP_PYTHON_EXCEPTION_H

#include <exception>

////////////////////////////////////////////////////////////////////////////////

namespace NCppPython
{
	/////////////////////////////////////////////////////////////////////////////////

	/// @brief The CppPythonException class provides custom exception handling.
	class CppPythonException : virtual public std::exception
	{
		public:
			///==========================================================================
			/// Methods
			
			/// Constructor
			CppPythonException();

			/// Parmeterized constructor to throw and handle exception message.
			CppPythonException(const char* constErrorString);

			/// Destructor
			virtual ~CppPythonException() throw ();

			/// Method to get error message.
			virtual const char * what () const throw ();

		protected:
			const char* m_constErrorString;
	};
};


#endif // CPP_PYTHON_EXCEPTION_H


