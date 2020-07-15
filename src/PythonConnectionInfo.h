#ifndef PYTHON_CONNECTION_INFO_H
#define PYTHON_CONNECTION_INFO_H


#include "CppToPythonInterface.h"
#include <iostream>


namespace NCppPython
{
	class PythonConnectionInfo
	{
		public:
			PythonConnectionInfo()
			{
			}

			virtual ~PythonConnectionInfo()
			{
			}

			void setPythonModuleName(std::string& strName);
			virtual std::string& getPythonModuleName() = 0;

			void setPythonClassName(std::string& strName);
			virtual std::string& getPythonClassName() = 0;

			void setPythonMethodName(std::string& strName);
			virtual std::string& getPythonMethodName() = 0;

			virtual void getPythonMethodArgs(PythonObjectWrapper& outArgumentsInfo) = 0;

		private:
			std::string m_oModuleName;
			std::string m_oClassName;
			std::string m_oMethodName;
	};

	class PtpSystemConfigPythonConnectionInfo : virtual public PythonConnectionInfo
	{
		public:
			PtpSystemConfigPythonConnectionInfo(
					std::string strModuleName,
					std::string strClassName,
					std::string strMethodName,
					std::string strKeyName,
					std::string strKeyValue);

			virtual ~PtpSystemConfigPythonConnectionInfo();

			void setPythonModuleName(std::string& strName);
			virtual std::string& getPythonModuleName();

			void setPythonClassName(std::string& strName);
			virtual std::string& getPythonClassName();

			void setPythonMethodName(std::string& strName);
			virtual std::string& getPythonMethodName();

			virtual void getPythonMethodArgs(PythonObjectWrapper& outArgumentsInfo);

		private:
			CppToPythonInterface m_oCppToPythonInterface;
			std::string m_oModuleName;
			std::string m_oClassName;
			std::string m_oMethodName;

			std::string m_strKeyName;
			std::string m_strKeyValue;
	};
	
	class PtpCameraConfigPythonConnectionInfo : virtual public PythonConnectionInfo
	{
		public:
			PtpCameraConfigPythonConnectionInfo(
					std::string strModuleName,
					std::string strClassName,
					std::string strMethodName,
					std::string strCameraIP,
					std::string strSiteCode,
					std::string strSiteLocation,
					std::string strUserName,
					std::string strPassword);

			virtual ~PtpCameraConfigPythonConnectionInfo();

			void setPythonModuleName(std::string& strName);
			virtual std::string& getPythonModuleName();

			void setPythonClassName(std::string& strName);
			virtual std::string& getPythonClassName();

			void setPythonMethodName(std::string& strName);
			virtual std::string& getPythonMethodName();

			virtual void getPythonMethodArgs(PythonObjectWrapper& outArgumentsInfo);

		private:
			CppToPythonInterface m_oCppToPythonInterface;
			std::string m_oModuleName;
			std::string m_oClassName;
			std::string m_oMethodName;

			std::string m_strCameraIP;
			std::string m_strSiteCode;
			std::string m_strSiteLocation;
			std::string m_strUserName;
			std::string m_strPassword;
	};
	
	class PtpRoutePythonConnectionInfo : virtual public PythonConnectionInfo
	{
		public:
			PtpRoutePythonConnectionInfo(
					std::string strModuleName,
					std::string strClassName,
					std::string strMethodName,
					std::string strRouteStartSiteCode,
					std::string strRouteEndSiteCode,
					double dDistanceKm,
					std::string strRouteIdentifierCode,
					std::string strRouteDescription);

			virtual ~PtpRoutePythonConnectionInfo();

			void setPythonModuleName(std::string& strName);
			virtual std::string& getPythonModuleName();

			void setPythonClassName(std::string& strName);
			virtual std::string& getPythonClassName();

			void setPythonMethodName(std::string& strName);
			virtual std::string& getPythonMethodName();

			virtual void getPythonMethodArgs(PythonObjectWrapper& outArgumentsInfo);

		private:
			CppToPythonInterface m_oCppToPythonInterface;
			std::string m_oModuleName;
			std::string m_oClassName;
			std::string m_oMethodName;

			std::string m_strRouteStartSiteCode;
			std::string m_strRouteEndSiteCode;
			double m_dDistanceKm;
			std::string m_strRouteIdentifierCode;
			std::string m_strRouteDescription;
	};
};


#endif // PYTHON_CONNECTION_INFO_H

