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
 * @file CppToPythonInterface.h
 * @author Dilip Kumar Sharma
 * @brief CPP interface to connect to Python Module
 * @copyright Dilip Kumar Sharma
 * @date 27th April 2019
 ***/
 
/**
 *
 * @section General description
 *
 * The CppToPythonInterface provides the interface functionality for C++
 * code to connect to Python module. This lets you avoid writing any
 * Python code in C++ code. 
 * This is a kind of Wrapper class over Python functions.
 *
 * @section Usage
 *
 * Call this module to import python module, create class object, call
 * class methods or functions.
 * 
 * 
 * Usage scenario:
 *
 * Importing a python module
 * Creating an object of Python class.
 *
 * @section input
 *
 * CppToPythonInterface class does not take any input.
 *
 * @section Compatibility
 *
 * The CppToPythonInterface code is writtern in C++ and is not cross platform compatible.
 *
 * @section Testing
 *
 * This has been tested for Python3.4.
 **/
 
////////////////////////////////////////////////////////////////////////////////

#ifndef CPP_TO_PYTHON_INTERFACE_H
#define CPP_TO_PYTHON_INTERFACE_H


#include "PythonObjectWrapper.h"
#include "LwtException.h"
#include <vector>

////////////////////////////////////////////////////////////////////////////////

namespace NCppPython
{
	/////////////////////////////////////////////////////////////////////////////////
	
	/// @brief The CppToPythonInterface class provides interface functionality to connect to Python code.
	class CppToPythonInterface
	{
		public:
			///==========================================================================
			/// Methods
			
			/// Constructor
			CppToPythonInterface();
			
			/// Destructor
			~CppToPythonInterface();
			
			/// @brief Method to import Python Module.
			/// @param[in] cpModuleName Python module name to import.
			/// @param[out] outModuleObject To hold C pointer for Python object.
			/// @return void
			/// @exception Throws custom LWTException if unable to import Python Module.
			void importPythonModule(const char* cpModuleName, PythonObjectWrapper& outModuleObject) throw(LWTException);
			
			/// @brief Method to create Python class object. Python module must be imported first before using this method, otherwise LWTException will be thrown.
			/// @param[in] cpClassName Python class name.
			/// @param[in] oModuleObject C pointer for Python object received from importPythonModule() method.
			/// @param[out] outInstanceObject To hold C pointer for Python object.
			/// @return void
			/// @exception Throws custom LWTException if unable to create instance of Python Class.
			void createClassObject(const char* cpClassName, PythonObjectWrapper& oModuleObject, PythonObjectWrapper& outInstanceObject) throw(LWTException);
			
			/// @brief Method to call a Python function class method. 
			/// @description Python module must be imported first before using this method, if calling Python function.
			///				 Python class object must be created first before using this method, if calling Python Class Method.
			/// @param[in] cpName Python function/method name.
			/// @param[in] oCallableObject C pointer for Python object received from importPythonModule() method or createClassObject() method.
			/// @param[in] inTupleObject C pointer for Python tuple object crated by calling helper method of this class.
			///			 	 This holds all the parameters to be passed to function/method.
			/// @param[out] outCode To hold return error/success code from Python function
			/// @param[out] outMessage To hold return error/success message from Python function
			/// @return void
			/// @exception Throws custom LWTException if unable to call Python function/method.
			void callMethod(const char* cpName, PythonObjectWrapper& oCallableObject, PythonObjectWrapper& inTupleObject, int& outCode, char*& outMessage) throw(LWTException);
			
			/// Helper interface methods

			/// @brief Method to construct Python float. 
			/// @param[in] dInput Double value.
			/// @param[out] outFloatObject C pointer for Python object to hold python float object
			/// @return void
			/// @exception Throws custom LWTException if unable to construct Python float object.
			void constructPythonFloat(double dInput, PythonObjectWrapper& outFloatObject) throw(LWTException);
			
			/// @brief Method to construct Python String. This returns Python 3 Unicode string 
			/// @param[in] cInputString C String
			/// @param[out] outStringObject C pointer for Python object to hold python string object
			/// @return void
			/// @exception Throws custom LWTException if unable to construct Python string object.
			void constructPythonString(const char* cInputString, PythonObjectWrapper& outStringObject) throw(LWTException);

			/// void constructPythonTuple(std::vector<PythonObjectWrapper>& inPythonObjects, PythonObjectWrapper& outTupleObject) throw(LWTException);
			/// void constructPythonTuple(PythonObjectWrapper& a, PythonObjectWrapper& b, PythonObjectWrapper& c, PythonObjectWrapper& outTupleObject) throw(LWTException);
	};
	/////////////////////////////////////////////////////////////////////////////////
};		// end of namespace NCppPython


#endif // CPP_TO_PYTHON_INTERFACE_H

