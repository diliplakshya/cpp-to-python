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
 * @file CppPythonUtils.cpp
 * @author Dilip Kumar Sharma
 * @brief CPP Python Utility Class
 * @copyright Dilip Kumar Sharma
 * @date 25th April 2019
 ***/
 
#include "CppPythonUtils.h"


using namespace NCppPython;

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Constructor method
 */
CppPythonUtils::CppPythonUtils()
{
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Destructor method
 */
CppPythonUtils::~CppPythonUtils()
{
}

////////////////////////////////////////////////////////////////////////////////

/// Helper interface methods

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Method to construct Python int.
 * @param[in] lInput long value.
 * @param[out] outIntObject C pointer for Python object to hold python int object
 * @return void
 * @exception Throws custom LWTException if unable to construct Python int object.
 */
void CppPythonUtils::constructPythonInt(long lInput, PythonObjectWrapper& outIntObject) throw(LWTException)
{
	outIntObject = PyLong_FromLong(lInput);

	if (!outIntObject.is())
		throw LWTException("CppPythonUtils::constructPythonInt. Error. Skipped. Unable to construct python int.");
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Method to construct Python float.
 * @param[in] dInput Double value.
 * @param[out] outFloatObject C pointer for Python object to hold python float object
 * @return void
 * @exception Throws custom LWTException if unable to onstruct Python float
 */
void CppPythonUtils::constructPythonFloat(double dInput, PythonObjectWrapper& outFloatObject) throw(LWTException)
{
	outFloatObject = PyFloat_FromDouble(dInput);
		
	if (!outFloatObject.is())
		throw LWTException("CppPythonUtils::constructPythonFloat. Error. Skipped. Unable to construct python float.");
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Method to construct Python string.
 * @param[in] cInputString C String
 * @param[out] outStringObject C pointer for Python object to hold python string object
 * @return void
 * @exception Throws custom LWTException if unable to onstruct Python string
 */
void CppPythonUtils::constructPythonString(const char* cInputString, PythonObjectWrapper& outStringObject) throw(LWTException)
{
	outStringObject = PyUnicode_FromString(cInputString);

	if (!outStringObject.is())
		throw LWTException("CppPythonUtils::constructPythonString. Error. Skipped. Unable to construct python string.");
}

////////////////////////////////////////////////////////////////////////////////

void CppPythonUtils::constructPythonTuple(PythonObjectWrapper& oPythonObjectWrapper1, 
						PythonObjectWrapper& oPythonObjectWrapper2,
						PythonObjectWrapper& outTupleObject) throw(LWTException)
{
	outTupleObject = PyTuple_New(2);
	oPythonObjectWrapper1.AddRef();
	oPythonObjectWrapper2.AddRef();

	if (!outTupleObject.is())
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Unable to construct tuple for python objects.");

	if (PyTuple_SetItem(outTupleObject, 0, oPythonObjectWrapper1))		// PyTuple_SetItem returns 0 on success
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");

	if (PyTuple_SetItem(outTupleObject, 1, oPythonObjectWrapper2))		// PyTuple_SetItem returns 0 on success
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");

	// Check again for reference count
	if (!outTupleObject.is())
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Failed to fill items in python tuple.");
}

////////////////////////////////////////////////////////////////////////////////

void CppPythonUtils::constructPythonTuple(PythonObjectWrapper& oPythonObjectWrapper1, 
						PythonObjectWrapper& oPythonObjectWrapper2, 
						PythonObjectWrapper& oPythonObjectWrapper3, 
						PythonObjectWrapper& outTupleObject) throw(LWTException)
{
	outTupleObject = PyTuple_New(3);
	oPythonObjectWrapper1.AddRef();
	oPythonObjectWrapper2.AddRef();
	oPythonObjectWrapper3.AddRef();

	if (!outTupleObject.is())
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Unable to construct tuple for python objects.");

	if (PyTuple_SetItem(outTupleObject, 0, oPythonObjectWrapper1))		// PyTuple_SetItem returns 0 on success
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");

	if (PyTuple_SetItem(outTupleObject, 1, oPythonObjectWrapper2))		// PyTuple_SetItem returns 0 on success
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");
		
	if (PyTuple_SetItem(outTupleObject, 2, oPythonObjectWrapper3))		// PyTuple_SetItem returns 0 on success
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");

	// Check again for reference count
	if (!outTupleObject.is())
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Failed to fill items in python tuple.");
}

////////////////////////////////////////////////////////////////////////////////

void CppPythonUtils::constructPythonTuple(std::vector<PythonObjectWrapper>& inPythonObjects, PythonObjectWrapper& outTupleObject) throw(LWTException)
{
	if (!inPythonObjects.size())
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Invalid(Empty) vector found while constructing python tuple.");

	outTupleObject = PyTuple_New(inPythonObjects.size());

	if (!outTupleObject.is())
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Unable to construct tuple for python objects.");

	for (unsigned short uiIterator = 0; uiIterator < inPythonObjects.size(); ++uiIterator)
	{
		if (!inPythonObjects[uiIterator].is())
			throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Invalid(NULL) vector element found while constructing python tuple.");

		inPythonObjects[uiIterator].AddRef();
		if (PyTuple_SetItem(outTupleObject, uiIterator, inPythonObjects[uiIterator]))		// PyTuple_SetItem returns 0 on success
			throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");
	}

	// Check again for reference count
	if (!outTupleObject.is())
		throw LWTException("CppPythonUtils::constructPythonTuple. Error. Skipped. Failed to fill items in python tuple.");
}

////////////////////////////////////////////////////////////////////////////////

void CppPythonUtils::setPythonDictionary(PythonObjectWrapper& oDictKey, PythonObjectWrapper& oDictValue, PythonObjectWrapper& outDictionaryObject) throw(LWTException)
{
	if (!outDictionaryObject.is())			/// Construct on first call only
	{
		outDictionaryObject = PyDict_New();	

		if (!outDictionaryObject.is())
			throw LWTException("CppPythonUtils::setPythonDictionary. Error. Skipped. Unable to construct dictionary for python objects.");
	}

	if (!oDictKey.is())
		throw LWTException("CppPythonUtils::setPythonDictionary. Error. Skipped. Invalid(NULL) key found while constructing python dictionary.");

	if (!oDictValue.is())
		throw LWTException("CppPythonUtils::setPythonDictionary. Error. Skipped. Invalid(NULL) value element found while constructing python dictionary.");
		
	if (PyDict_SetItem(outDictionaryObject, oDictKey, oDictValue))									// PyDict_SetItem returns 0 on success
		throw LWTException("CppPythonUtils::setPythonDictionary. Error. Skipped. Unable to set item for python dictionary.");
}

////////////////////////////////////////////////////////////////////////////////


void CppPythonUtils::constructPythonDictionary(std::vector<CppPythonUtils::Pair>& inPythonObjects, PythonObjectWrapper& outDictionaryObject) throw(LWTException)
{
	if (!inPythonObjects.size())
		throw LWTException("CppPythonUtils::constructPythonDictionary. Error. Skipped. Invalid(Empty) vector found while constructing python dictionary.");

	outDictionaryObject = PyDict_New();

	if (!outDictionaryObject.is())
		throw LWTException("CppPythonUtils::constructPythonDictionary. Error. Skipped. Unable to construct dictionary for python objects.");

	for (unsigned short uiIterator = 0; uiIterator < inPythonObjects.size(); ++uiIterator)
	{
		if (!inPythonObjects[uiIterator].key.is() || !inPythonObjects[uiIterator].value.is())
			throw LWTException("CppPythonUtils::constructPythonDictionary. Error. Skipped. Invalid(NULL) vector element found while constructing python dictionary.");

		if (PyDict_SetItem(outDictionaryObject, inPythonObjects[uiIterator].key, inPythonObjects[uiIterator].value))						// PyDict_SetItem returns 0 on success
			throw LWTException("CppPythonUtils::constructPythonDictionary. Error. Skipped. Unable to set item for python dictionary.");
	}

	// Check again for reference count
	if (!outDictionaryObject.is())
		throw LWTException("CppPythonUtils::constructPythonDictionary. Error. Skipped. Failed to fill items in python dictionary.");
}

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

