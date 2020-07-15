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
 * @file CppToPythonInterface.hcpp
 * @author Dilip Kumar Sharma
 * @brief CPP interface to connect to Python Module
 * @copyright Dilip Kumar Sharma
 * @date 27th April 2019
 ***/
 
#include "CppToPythonInterface.h"


using namespace NCppPython;

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Constructor method
 */
CppToPythonInterface::CppToPythonInterface()
{
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Destructor method
 */
CppToPythonInterface::~CppToPythonInterface()
{
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Method to import Python Module.
 * @param[in] cpModuleName Python module name to import.
 * @param[out] outModuleObject To hold C pointer for Python object.
 * @return void
 * @exception Throws custom LWTException if unable to import Python Module.
 */
void CppToPythonInterface::importPythonModule(const char* cpModuleName, PythonObjectWrapper& outModuleObject) throw(LWTException)
{
	// Build the name object
	PythonObjectWrapper oModuleNameObject = PyUnicode_FromString(cpModuleName);

	if (cpModuleName == NULL)
		throw LWTException("CppToPythonInterface::importPythonModule. Error. Skipped. Invalid(NULL) module name argument found while importing module");

	// Load the module object
	if (!oModuleNameObject.is())
		throw LWTException("CppToPythonInterface::importPythonModule. Error. Skipped. Unable to get named object for module.");

		outModuleObject = PyImport_Import(oModuleNameObject);

	if (!outModuleObject.is())
		throw LWTException("CppToPythonInterface::importPythonModule. Error. Skipped. Unable to import python module.");
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Method to create Python class object. Python module must be imported first before using this method, otherwise LWTException will be thrown.
 * @param[in] cpClassName Python module name to import.
 * @param[in] oModuleObject C pointer for Python object received from importPythonModule() method.
 * @param[out] outInstanceObject To hold C pointer for Python object.
 * @return void
 * @exception Throws custom LWTException if unable to create instance of Python Class.
 */
void CppToPythonInterface::createClassObject(const char* cpClassName, PythonObjectWrapper& oModuleObject, PythonObjectWrapper& outInstanceObject) throw(LWTException)
{
	if (!oModuleObject.is())
		throw LWTException("CppToPythonInterface::createClassObject. Error. Skipped. First Import Python Module before creating class object.");
		
	if (cpClassName == NULL)
		throw LWTException("CppToPythonInterface::createClassObject. Error. Skipped. Invalid(NULL) class name argument found while calling class object.");
		
	PythonObjectWrapper oClassObject = PyObject_GetAttrString(oModuleObject, cpClassName);
	
	if (!oClassObject.is())
		throw LWTException("CppToPythonInterface::createClassObject. Error. Skipped. Unable to build the name of callable class.");

	// Create an instance of the class
   // if (!PyCallable_Check(oClassObject))
	//	throw LWTException("CppToPythonInterface::createClassObject. Error. Skipped. Python class not callable.");
    
	PythonObjectWrapper oArguments = Py_BuildValue("()");
    outInstanceObject = PyEval_CallObject(oClassObject, oArguments);
        
    if (!outInstanceObject.is())
		throw LWTException("CppToPythonInterface::createClassObject. Error. Skipped. Unable to create object of class.");
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Method to call a Python function class method.
 * @description Python module must be imported first before using this method, if calling Python function.
 * 				Python class object must be created first before using this method, if calling Python Class Method.
 * @param[in] cpName Python function/method name.
 * @param[in] oCallableObject C pointer for Python object received from importPythonModule() method or createClassObject() method.
 * @param[in] inTupleObject C pointer for Python tuple object crated by calling helper method of this class.
 * @param[out] outCode To hold return error/success code from Python function
 * @param[out] outMessage To hold return error/success message from Python function
 * @return void
 * @exception Throws custom LWTException if unable to call Python function/method.
 */
void CppToPythonInterface::callMethod(const char* cpName, PythonObjectWrapper& oCallableObject, 
			PythonObjectWrapper& inTupleObject, int& outCode, char*& outMessage) 
			throw(LWTException)
{
	// Arguments validation starts
	if (!oCallableObject.is())
		throw LWTException("CppToPythonInterface::callMethod. Error. Skipped. Invalid callable object provided.");

	if (!inTupleObject.is() || cpName == NULL)
		throw LWTException("CppToPythonInterface::callMethod. Error. Skipped. Invalid(NULL) argument found while calling class method.");
		
	if (!PyTuple_CheckExact(inTupleObject))
		throw LWTException("CppToPythonInterface::callMethod. Error. Skipped. Argument must be of type tuple.");
	// Arguments validation Ends

	PythonObjectWrapper oMethodObject = PyObject_GetAttrString(oCallableObject, cpName);

	if (!oMethodObject.is())
		throw LWTException("CppToPythonInterface::callMethod. Error. Skipped. Unable to build the name of callable method.");
		
	if(!PyCallable_Check(oMethodObject))
		throw LWTException("CppToPythonInterface::callMethod. Error. Skipped. Method object is not callable.");

	PythonObjectWrapper oCallObject = PyObject_CallObject(oMethodObject, inTupleObject);

    if (!oCallObject.is())
		throw LWTException("CppToPythonInterface::callMethod. Error. Skipped. Unable to call python method.");

	int result = PyArg_ParseTuple(oCallObject, "is", &outCode, &outMessage); // One int and and one string
}

/// Helper interface methods

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Method to construct Python float.
 * @param[in] dInput Double value.
 * @param[out] outFloatObject C pointer for Python object to hold python float object
 * @return void
 * @exception Throws custom LWTException if unable to onstruct Python float
 */
void CppToPythonInterface::constructPythonFloat(double dInput, PythonObjectWrapper& outFloatObject) throw(LWTException)
{
	outFloatObject = PyFloat_FromDouble(dInput);
		
	if (!outFloatObject.is())
		throw LWTException("CppToPythonInterface::constructPythonFloat. Error. Skipped. Unable to construct python float.");
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Method to construct Python string.
 * @param[in] cInputString C String
 * @param[out] outStringObject C pointer for Python object to hold python string object
 * @return void
 * @exception Throws custom LWTException if unable to onstruct Python string
 */
void CppToPythonInterface::constructPythonString(const char* cInputString, PythonObjectWrapper& outStringObject) throw(LWTException)
{
	outStringObject = PyUnicode_FromString(cInputString);
		
	if (!outStringObject.is())
		throw LWTException("CppToPythonInterface::constructPythonString. Error. Skipped. Unable to construct python string.");
}

/**
void CppToPythonInterface::constructPythonTuple(std::vector<PythonObjectWrapper>& inPythonObjects, PythonObjectWrapper& outTupleObject) throw(LWTException)
{
	if (!inPythonObjects.size())
		throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Invalid(Empty) vector found while constructing python tuple.");

	outTupleObject = PyTuple_New(inPythonObjects.size());

	if (!outTupleObject.is())
		throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Unable to construct tuple for python objects.");

	for (unsigned short uiIterator = 0; uiIterator < inPythonObjects.size(); ++uiIterator)
	{
		if (!inPythonObjects[uiIterator].is())
			throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Invalid(NULL) vector element found while constructing python tuple.");

		inPythonObjects[uiIterator].AddRef();
		if (PyTuple_SetItem(outTupleObject, uiIterator, inPythonObjects[uiIterator]))		// PyTuple_SetItem returns 0 on success
		{
			outTupleObject.Release();
			throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");
		}
	}

	// Check again for reference count
	if (!outTupleObject.is())
		throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Failed to fill items in python tuple.");
}

void CppToPythonInterface::constructPythonTuple(PythonObjectWrapper& a, PythonObjectWrapper& b, PythonObjectWrapper& c, PythonObjectWrapper& outTupleObject) throw(LWTException)
{
	outTupleObject = PyTuple_New(3);
	a.AddRef();
	b.AddRef();
	c.AddRef();

	if (!outTupleObject.is())
		throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Unable to construct tuple for python objects.");

	if (PyTuple_SetItem(outTupleObject, 0, a))		// PyTuple_SetItem returns 0 on success
		throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");

	if (PyTuple_SetItem(outTupleObject, 1, b))		// PyTuple_SetItem returns 0 on success
		throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");
		
	if (PyTuple_SetItem(outTupleObject, 2, c))		// PyTuple_SetItem returns 0 on success
		throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Unable to set item for python tuple.");

	// Check again for reference count
	if (!outTupleObject.is())
		throw LWTException("CppToPythonInterface::constructPythonTuple. Error. Skipped. Failed to fill items in python tuple.");
}
**/
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
