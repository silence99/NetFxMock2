#pragma once
#include <log4cplus/logger.h>


class ILog
{
public:
	ILog();
	~ILog();
	static bool IsInitialized;
	static log4cplus::Logger Logger;

	void Log_Trace(char* pszFmtString, ...);
	void Log_Debug(char* pszFmtString, ...);
	void Log_Info(char* pszFmtString, ...);
	void Log_Warn(char* pszFmtString, ...);
	void Log_Error(char* pszFmtString, ...);
	void Log_Fatal(char* pszFmtString, ...);
};

