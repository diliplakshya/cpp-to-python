////////////////////////////////////////////////////////////////////////////////
//
//                DILIP KUMAR SHARMA CONFIDENTIAL & PROPRIETARY
//				--------------------------------------------
// 	Project : Interface module for Cpp to Python
//	File	: CppPythonUtils.h
//  Date	: 25th April 2019
//  Author	: Dilip Kumar Sharma
//  
// 
// 
//
////////////////////////////////////////////////////////////////////////////////

/***
 * @file CppPythonUtils.h
 * @author Dilip Kumar Sharma
 * @brief CPP Python Utility Class
 * @copyright Dilip Kumar Sharma
 * @date 25th April 2019
 ***/
 
/**
 *
 * @section General description
 *
 * The CppPythonUtils provides the utility functionality for C++
 * code to get Python objects. This lets you avoid writing any
 * Python code in C++ code. 
 * This is a kind of Wrapper class over Python objects.
 *
 * @section Usage
 *
 * Call this module to get Python objects.
 * 
 * 
 * Usage scenario:
 *
 * Constructing Python String, Tuple etc.
 *
 * @section input
 *
 * CppPythonUtils class does not take any input.
 *
 * @section Compatibility
 *
 * The CppPythonUtils code is writtern in C++ and is not cross platform compatible.
 *
 * @section Testing
 *
 * This has been tested for Python3.4.
 **/
 
////////////////////////////////////////////////////////////////////////////////

#ifndef CPP_PYTHON_UTILS_H
#define CPP_PYTHON_UTILS_H


#include "PythonObjectWrapper.h"
#include "LwtException.h"
#include <vector>

////////////////////////////////////////////////////////////////////////////////

namespace NCppPython
{
	/////////////////////////////////////////////////////////////////////////////////
	
	/// @brief The CppPythonUtils class provides utility functionality to connect to Python code.
	class CppPythonUtils
	{
		public:
			///==========================================================================
			/// Methods
			
			/// Constructor
			CppPythonUtils();
			
			/// Destructor
			~CppPythonUtils();
			
			/// Structure to hold dictionary key value pair
			typedef struct KeyValue
			{
				PythonObjectWrapper key;
				PythonObjectWrapper value;
			} Pair;
			
			/// Utility interface methods

			/// @brief Method to construct Python int. 
			/// @param[in] lInput long value.
			/// @param[out] outIntObject C pointer for Python object to hold python int object
			/// @return void
			/// @exception Throws custom LWTException if unable to construct Python int object.
			void constructPythonInt(long lInput, PythonObjectWrapper& outIntObject) throw(LWTException);

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

			void constructPythonTuple(std::vector<PythonObjectWrapper>& inPythonObjects, PythonObjectWrapper& outTupleObject) throw(LWTException);
			void constructPythonTuple(PythonObjectWrapper& oPythonObjectWrapper1, PythonObjectWrapper& oPythonObjectWrapper2, PythonObjectWrapper& outTupleObject) throw(LWTException);
			void constructPythonTuple(PythonObjectWrapper& oPythonObjectWrapper1, PythonObjectWrapper& oPythonObjectWrapper2, PythonObjectWrapper& oPythonObjectWrapper3, PythonObjectWrapper& outTupleObject) throw(LWTException);
			/// void constructPythonTuple(PythonObjectWrapper& oPythonObjectWrapper1, PythonObjectWrapper& oPythonObjectWrapper2, PythonObjectWrapper& outTupleObject) throw(LWTException);
			
			void setPythonDictionary(PythonObjectWrapper& oDictKey, PythonObjectWrapper& oDictValue, PythonObjectWrapper& outDictionaryObject) throw(LWTException);
			void constructPythonDictionary(std::vector<Pair>& inPythonObjects, PythonObjectWrapper& outDictionaryObject) throw(LWTException);
	};
	/////////////////////////////////////////////////////////////////////////////////
};		// end of namespace NCppPython


#endif // CPP_PYTHON_UTILS_H


