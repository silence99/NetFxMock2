#pragma once

#ifndef NAME_BUFFER_SIZE
#define NAME_BUFFER_SIZE 1024
#include <CorHdr.h>
#include <cor.h>
#include <corprof.h>
#include "resource.h"

class Util
{
public:
	Util();
	~Util();

	static int wchar2char(const wchar_t* wchar, char* out);
	static HRESULT GetFullMethodName(ATL::CComQIPtr<ICorProfilerInfo2> profiler2, FunctionID functionID, LPWSTR wszMethod, int cMethod);
};

#endif

