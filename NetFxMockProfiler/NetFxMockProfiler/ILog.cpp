#include "stdafx.h"
#include "ILog.h"

#include <log4cplus/loglevel.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>

ILog::ILog()
{
	if (!IsInitialized)
	{
		IsInitialized = true;
		log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log.properties"));
		Logger = log4cplus::Logger::getRoot();
	}
}


ILog::~ILog()
{
}

void ILog::Log_Trace(char* pszFmtString, ...)
{
	CHAR szBuffer[4096];
	va_list args;
	va_start(args, pszFmtString);
	vsprintf_s(szBuffer, pszFmtString, args);
	va_end(args);
	LOG4CPLUS_TRACE(Logger, szBuffer);
}
void ILog::Log_Debug(char* pszFmtString, ...)
{
	CHAR szBuffer[4096];
	va_list args;
	va_start(args, pszFmtString);
	vsprintf_s(szBuffer, pszFmtString, args);
	va_end(args);
	LOG4CPLUS_DEBUG(Logger, szBuffer);
}
void ILog::Log_Info(char* pszFmtString, ...)
{
	CHAR szBuffer[4096];
	va_list args;
	va_start(args, pszFmtString);
	vsprintf_s(szBuffer, pszFmtString, args);
	va_end(args);
	LOG4CPLUS_INFO(Logger, szBuffer);
}
void ILog::Log_Warn(char* pszFmtString, ...)
{
	CHAR szBuffer[4096];
	va_list args;
	va_start(args, pszFmtString);
	vsprintf_s(szBuffer, pszFmtString, args);
	va_end(args);
	LOG4CPLUS_WARN(Logger, szBuffer);
}
void ILog::Log_Error(char* pszFmtString, ...)
{
	CHAR szBuffer[4096];
	va_list args;
	va_start(args, pszFmtString);
	vsprintf_s(szBuffer, pszFmtString, args);
	va_end(args);
	LOG4CPLUS_ERROR(Logger, szBuffer);
}
void ILog::Log_Fatal(char* pszFmtString, ...)
{
	CHAR szBuffer[4096];
	va_list args;
	va_start(args, pszFmtString);
	vsprintf_s(szBuffer, pszFmtString, args);
	va_end(args);
	LOG4CPLUS_FATAL(Logger, szBuffer);
}


bool ILog::IsInitialized = false;
log4cplus::Logger ILog::Logger;