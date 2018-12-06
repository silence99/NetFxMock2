#include "stdafx.h"
#include "EnterFunctionListener.h"


EnterFunctionListener::EnterFunctionListener(ATL::CComQIPtr<ICorProfilerInfo> pCorProfilerInfo,
	ATL::CComQIPtr<ICorProfilerInfo2> pCorProfilerInfo2,
	ATL::CComQIPtr<ICorProfilerInfo3> pCorProfilerInfo3,
	ATL::CComQIPtr<ICorProfilerInfo4> pCorProfilerInfo4)
{
	_pCorProfilerInfo = pCorProfilerInfo;
	_pCorProfilerInfo2 = pCorProfilerInfo2;
	_pCorProfilerInfo3 = pCorProfilerInfo3;
	_pCorProfilerInfo4 = pCorProfilerInfo4;
}


EnterFunctionListener::~EnterFunctionListener()
{
}

void EnterFunctionListener::Accept(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo)
{
	ProcessSetMock(functionID, clientData, frameInfo, argumentInfo);
}

bool EnterFunctionListener::IsFunctionToProcess(FunctionID funcId, char* pFuncName)
{
	WCHAR wszName[NAME_BUFFER_SIZE] = { 0 };
	Util::GetFullMethodName(_pCorProfilerInfo2, funcId, wszName, NAME_BUFFER_SIZE);

	char szName[2 * NAME_BUFFER_SIZE] = { 0 };
	Util::wchar2char(wszName, szName);

	return strcmp(pFuncName, szName) == 0;
}

void SetMock(FunctionID functionId, FunctionID mockId)
{

}
void EnterFunctionListener::ProcessSetMock(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo)
{
	if (!IsFunctionToProcess(functionID, "NetFxMock.MockUtils.SetMock"))
	{
		return;
	}

	ObjectID instanceId = 0;
	FunctionID methodId = 0;
	WCHAR wszMethodName[NAME_BUFFER_SIZE] = { 0 };
	char szMethodName[2 * NAME_BUFFER_SIZE] = { 0 };
	FunctionID mockId = 0;
	WCHAR wszMockName[NAME_BUFFER_SIZE] = { 0 };
	char szMockName[2 * NAME_BUFFER_SIZE] = { 0 };

	memcpy(&instanceId, (const void*)argumentInfo->ranges[0].startAddress, argumentInfo->ranges[0].length);
	memcpy(&methodId, (const void*)argumentInfo->ranges[1].startAddress, argumentInfo->ranges[1].length);
	memcpy(&mockId, (const void*)argumentInfo->ranges[2].startAddress, argumentInfo->ranges[2].length);
	Util::GetFullMethodName(_pCorProfilerInfo2, methodId, wszMethodName, NAME_BUFFER_SIZE);
	Util::GetFullMethodName(_pCorProfilerInfo2, mockId, wszMockName, NAME_BUFFER_SIZE);

	Util::wchar2char(wszMethodName, szMethodName);
	Util::wchar2char(wszMockName, szMockName);

	Log_Info("ProcessSetMock function: func[%s], mock[%s]", szMethodName, szMockName);

	SetMock(methodId, mockId);
}


