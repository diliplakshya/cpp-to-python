#include "PythonConnectionInfo.h"


using namespace NCppPython;


// PtpSystemConfigPythonConnectionInfo
PtpSystemConfigPythonConnectionInfo::PtpSystemConfigPythonConnectionInfo(
		std::string strModuleName,
		std::string strClassName,
		std::string strMethodName,
		std::string strKeyName,
		std::string strKeyValue) :
		m_oModuleName(strModuleName),
		m_oClassName(strClassName), 
		m_oMethodName(strMethodName),
		m_strKeyName(strKeyName),
		m_strKeyValue(strKeyValue)
{
	setPythonModuleName(m_oModuleName);
	setPythonClassName(m_oClassName);
	setPythonMethodName(m_oMethodName);
}

PtpSystemConfigPythonConnectionInfo::~PtpSystemConfigPythonConnectionInfo()
{
}

void PtpSystemConfigPythonConnectionInfo::setPythonModuleName(std::string& strName)
{
	m_oModuleName = strName;
}

std::string& PtpSystemConfigPythonConnectionInfo::getPythonModuleName()
{
	return m_oModuleName;
}

void PtpSystemConfigPythonConnectionInfo::setPythonClassName(std::string& strName)
{
	m_oClassName = strName;
}

std::string& PtpSystemConfigPythonConnectionInfo::getPythonClassName()
{
	return m_oClassName;
}

void PtpSystemConfigPythonConnectionInfo::setPythonMethodName(std::string& strName)
{
	m_oMethodName = strName;
}

std::string& PtpSystemConfigPythonConnectionInfo::getPythonMethodName()
{
	return m_oMethodName;
}

void PtpSystemConfigPythonConnectionInfo::getPythonMethodArgs(PythonObjectWrapper& outArgumentsInfo)
{
	// keyName
	PythonObjectWrapper oStringKeyNameObject;
	m_oCppToPythonInterface.constructPythonString(m_strKeyName.c_str(), oStringKeyNameObject);
	oStringKeyNameObject.AddRef();

	// keyName
	PythonObjectWrapper oStringKeyValueObject;
	m_oCppToPythonInterface.constructPythonString(m_strKeyValue.c_str(), oStringKeyValueObject);
	oStringKeyValueObject.AddRef();

	outArgumentsInfo = PyTuple_New(2);
	
	if (!outArgumentsInfo.is())
		throw LWTException("PtpSystemConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to construct python aurguents tuple.");

	if (PyTuple_SetItem(outArgumentsInfo, 0, oStringKeyNameObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpSystemConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item first for python tuple.");

	if (PyTuple_SetItem(outArgumentsInfo, 1, oStringKeyValueObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpSystemConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item second for python tuple.");

	// Check again for reference count
	if (!outArgumentsInfo.is())
		throw LWTException("PtpSystemConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Failed to fill items in python tuple.");
}

// PtpCameraConfigPythonConnectionInfo
PtpCameraConfigPythonConnectionInfo::PtpCameraConfigPythonConnectionInfo( 
		std::string strModuleName,
		std::string strClassName,
		std::string strMethodName,
		std::string strCameraIP,
		std::string strSiteCode,
		std::string strSiteLocation,
		std::string strUserName,
		std::string strPassword) :
		m_oModuleName(strModuleName),
		m_oClassName(strClassName), 
		m_oMethodName(strMethodName),
		m_strCameraIP(strCameraIP),
		m_strSiteCode(strSiteCode),
		m_strSiteLocation(strSiteLocation),
		m_strUserName(strUserName),
		m_strPassword(strPassword)
{
	setPythonModuleName(m_oModuleName);
	setPythonClassName(m_oClassName);
	setPythonMethodName(m_oMethodName);
}

PtpCameraConfigPythonConnectionInfo::~PtpCameraConfigPythonConnectionInfo()
{
}

void PtpCameraConfigPythonConnectionInfo::setPythonModuleName(std::string& strName)
{
	m_oModuleName = strName;
}

std::string& PtpCameraConfigPythonConnectionInfo::getPythonModuleName()
{
	return m_oModuleName;
}

void PtpCameraConfigPythonConnectionInfo::setPythonClassName(std::string& strName)
{
	m_oClassName = strName;
}

std::string& PtpCameraConfigPythonConnectionInfo::getPythonClassName()
{
	return m_oClassName;
}

void PtpCameraConfigPythonConnectionInfo::setPythonMethodName(std::string& strName)
{
	m_oMethodName = strName;
}

std::string& PtpCameraConfigPythonConnectionInfo::getPythonMethodName()
{
	return m_oMethodName;
}

void PtpCameraConfigPythonConnectionInfo::getPythonMethodArgs(PythonObjectWrapper& outArgumentsInfo)
{
	// cameraIP
	PythonObjectWrapper oStringCameraIPObject;
	m_oCppToPythonInterface.constructPythonString(m_strCameraIP.c_str(), oStringCameraIPObject);
	oStringCameraIPObject.AddRef();
	
	// siteCode
	PythonObjectWrapper oStringSiteCodeObject;
	m_oCppToPythonInterface.constructPythonString(m_strSiteCode.c_str(), oStringSiteCodeObject);
	oStringSiteCodeObject.AddRef();
	
	// siteLocation
	PythonObjectWrapper oStringSiteLocationObject;
	m_oCppToPythonInterface.constructPythonString(m_strSiteLocation.c_str(), oStringSiteLocationObject);
	oStringSiteLocationObject.AddRef();
	
	// username
	PythonObjectWrapper oStringUsernameObject;
	m_oCppToPythonInterface.constructPythonString(m_strUserName.c_str(), oStringUsernameObject);
	oStringUsernameObject.AddRef();
	
	// password
	PythonObjectWrapper oStringPasswordObject;
	m_oCppToPythonInterface.constructPythonString(m_strPassword.c_str(), oStringPasswordObject);
	oStringPasswordObject.AddRef();	

	outArgumentsInfo = PyTuple_New(5);
	
	if (!outArgumentsInfo.is())
		throw LWTException("PtpCameraConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to construct python aurguents tuple.");

	if (PyTuple_SetItem(outArgumentsInfo, 0, oStringCameraIPObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpCameraConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item first for python tuple.");

	if (PyTuple_SetItem(outArgumentsInfo, 1, oStringSiteCodeObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpCameraConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item second for python tuple.");
		
	if (PyTuple_SetItem(outArgumentsInfo, 2, oStringSiteLocationObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpCameraConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item third for python tuple.");
		
	if (PyTuple_SetItem(outArgumentsInfo, 3, oStringUsernameObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpCameraConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item third for python tuple.");
		
	if (PyTuple_SetItem(outArgumentsInfo, 4, oStringPasswordObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpCameraConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item third for python tuple.");

	// Check again for reference count
	if (!outArgumentsInfo.is())
		throw LWTException("PtpCameraConfigPythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Failed to fill items in python tuple.");
}

// PtpRoutePythonConnectionInfo
PtpRoutePythonConnectionInfo::PtpRoutePythonConnectionInfo(
		std::string strModuleName,
		std::string strClassName,
		std::string strMethodName, 
		std::string strRouteStartSiteCode,
		std::string strRouteEndSiteCode,
		double dDistanceKm,
		std::string strRouteIdentifierCode,
		std::string strRouteDescription) :
		m_oModuleName(strModuleName),
		m_oClassName(strClassName), 
		m_oMethodName(strMethodName),
		m_strRouteStartSiteCode(strRouteStartSiteCode),
		m_strRouteEndSiteCode(strRouteEndSiteCode),
		m_dDistanceKm(dDistanceKm),
		m_strRouteIdentifierCode(strRouteIdentifierCode),
		m_strRouteDescription(strRouteDescription)
{
	setPythonModuleName(m_oModuleName);
	setPythonClassName(m_oClassName);
	setPythonMethodName(m_oMethodName);
}

PtpRoutePythonConnectionInfo::~PtpRoutePythonConnectionInfo()
{
}

void PtpRoutePythonConnectionInfo::setPythonModuleName(std::string& strName)
{
	m_oModuleName = strName;
}

std::string& PtpRoutePythonConnectionInfo::getPythonModuleName()
{
	return m_oModuleName;
}

void PtpRoutePythonConnectionInfo::setPythonClassName(std::string& strName)
{
	m_oClassName = strName;
}

std::string& PtpRoutePythonConnectionInfo::getPythonClassName()
{
	return m_oClassName;
}

void PtpRoutePythonConnectionInfo::setPythonMethodName(std::string& strName)
{
	m_oMethodName = strName;
}

std::string& PtpRoutePythonConnectionInfo::getPythonMethodName()
{
	return m_oMethodName;
}

void PtpRoutePythonConnectionInfo::getPythonMethodArgs(PythonObjectWrapper& outArgumentsInfo)
{
	// routeStartSiteCode
	PythonObjectWrapper oStringRouteStartSiteCodeObject;
	m_oCppToPythonInterface.constructPythonString(m_strRouteStartSiteCode.c_str(), oStringRouteStartSiteCodeObject);
	oStringRouteStartSiteCodeObject.AddRef();
	
	// routeEndSiteCode
	PythonObjectWrapper oStringRouteEndSiteCodeObject;
	m_oCppToPythonInterface.constructPythonString(m_strRouteEndSiteCode.c_str(), oStringRouteEndSiteCodeObject);
	oStringRouteEndSiteCodeObject.AddRef();
	
	// distanceKm
	PythonObjectWrapper oFloatDistanceObject;
	m_oCppToPythonInterface.constructPythonFloat(m_dDistanceKm, oFloatDistanceObject);
	oFloatDistanceObject.AddRef();
	
	// routeIdentifierCode
	PythonObjectWrapper oStringRouteIdentifierObject;
	m_oCppToPythonInterface.constructPythonString(m_strRouteIdentifierCode.c_str(), oStringRouteIdentifierObject);
	oStringRouteIdentifierObject.AddRef();
	
	// routeDescription
	PythonObjectWrapper oStringRouteDescriptionObject;
	m_oCppToPythonInterface.constructPythonString(m_strRouteDescription.c_str(), oStringRouteDescriptionObject);
	oStringRouteDescriptionObject.AddRef();	

	outArgumentsInfo = PyTuple_New(5);
	
	if (!outArgumentsInfo.is())
		throw LWTException("PtpRoutePythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to construct python aurguents tuple.");

	if (PyTuple_SetItem(outArgumentsInfo, 0, oStringRouteStartSiteCodeObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpRoutePythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item first for python tuple.");

	if (PyTuple_SetItem(outArgumentsInfo, 1, oStringRouteEndSiteCodeObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpRoutePythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item second for python tuple.");
		
	if (PyTuple_SetItem(outArgumentsInfo, 2, oFloatDistanceObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpRoutePythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item third for python tuple.");
		
	if (PyTuple_SetItem(outArgumentsInfo, 3, oStringRouteIdentifierObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpRoutePythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item third for python tuple.");
		
	if (PyTuple_SetItem(outArgumentsInfo, 4, oStringRouteDescriptionObject))		// PyTuple_SetItem returns 0 on success
		throw LWTException("PtpRoutePythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Unable to set item third for python tuple.");

	// Check again for reference count
	if (!outArgumentsInfo.is())
		throw LWTException("PtpRoutePythonConnectionInfo::getPythonMethodArgsInfoForDataUpdate. Error. Skipped. Failed to fill items in python tuple.");
}
