#pragma once
#include "resource.h"       // main symbols
#include <CorHdr.h>
#include <cor.h>
#include <corprof.h>
#include "ILog.h"
#include "Util.h"

class EnterFunctionListener: public ILog
{
public:
	EnterFunctionListener(ATL::CComQIPtr<ICorProfilerInfo>, ATL::CComQIPtr<ICorProfilerInfo2>, ATL::CComQIPtr<ICorProfilerInfo3>, ATL::CComQIPtr<ICorProfilerInfo4>);
	~EnterFunctionListener();

	ATL::CComQIPtr<ICorProfilerInfo> _pCorProfilerInfo;
	ATL::CComQIPtr<ICorProfilerInfo2> _pCorProfilerInfo2;
	ATL::CComQIPtr<ICorProfilerInfo3> _pCorProfilerInfo3;
	ATL::CComQIPtr<ICorProfilerInfo4> _pCorProfilerInfo4;

	void Accept(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo);

private:
	void ProcessSetMock(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo);
	bool IsFunctionToProcess(FunctionID funcId, char* pFuncName);
};

