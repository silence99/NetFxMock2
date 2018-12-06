// ProfilerInterface.cpp : Implementation of CProfilerInterface

#include "stdafx.h"
#include "ProfilerInterface.h"
#include "EnterFunctionListener.h"


CProfilerInterface* g_pICorProfilerCallback = NULL;

// our real handler for FunctionEnter notification
void CProfilerInterface::Enter(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo)
{
	WCHAR szMethodName[NAME_BUFFER_SIZE];
	GetFullMethodName(functionID, szMethodName, NAME_BUFFER_SIZE);
	char szName[2 * NAME_BUFFER_SIZE] = { 0 };
	Util::wchar2char(szMethodName, szName);
	Log_Info("enter function: %s", szName);

	EnterFunctionListener listener(pCorProfilerInfo, pCorProfilerInfo2, pCorProfilerInfo3, pCorProfilerInfo4);
	listener.Accept(functionID, clientData, frameInfo, argumentInfo);
}

// CProfilerInterface
STDMETHODIMP CProfilerInterface::SetEvent()
{
	//COR_PRF_MONITOR_NONE	= 0,
	//COR_PRF_MONITOR_FUNCTION_UNLOADS	= 0x1,
	//COR_PRF_MONITOR_CLASS_LOADS	= 0x2,
	//COR_PRF_MONITOR_MODULE_LOADS	= 0x4,
	//COR_PRF_MONITOR_ASSEMBLY_LOADS	= 0x8,
	//COR_PRF_MONITOR_APPDOMAIN_LOADS	= 0x10,
	//COR_PRF_MONITOR_JIT_COMPILATION	= 0x20,
	//COR_PRF_MONITOR_EXCEPTIONS	= 0x40,
	//COR_PRF_MONITOR_GC	= 0x80,
	//COR_PRF_MONITOR_OBJECT_ALLOCATED	= 0x100,
	//COR_PRF_MONITOR_THREADS	= 0x200,
	//COR_PRF_MONITOR_REMOTING	= 0x400,
	//COR_PRF_MONITOR_CODE_TRANSITIONS	= 0x800,
	//COR_PRF_MONITOR_ENTERLEAVE	= 0x1000,
	//COR_PRF_MONITOR_CCW	= 0x2000,
	//COR_PRF_MONITOR_REMOTING_COOKIE	= 0x4000 | COR_PRF_MONITOR_REMOTING,
	//COR_PRF_MONITOR_REMOTING_ASYNC	= 0x8000 | COR_PRF_MONITOR_REMOTING,
	//COR_PRF_MONITOR_SUSPENDS	= 0x10000,
	//COR_PRF_MONITOR_CACHE_SEARCHES	= 0x20000,
	//COR_PRF_MONITOR_CLR_EXCEPTIONS	= 0x1000000,
	//COR_PRF_MONITOR_ALL	= 0x107ffff,
	//COR_PRF_ENABLE_REJIT	= 0x40000,
	//COR_PRF_ENABLE_INPROC_DEBUGGING	= 0x80000,
	//COR_PRF_ENABLE_JIT_MAPS	= 0x100000,
	//COR_PRF_DISABLE_INLINING	= 0x200000,
	//COR_PRF_DISABLE_OPTIMIZATIONS	= 0x400000,
	//COR_PRF_ENABLE_OBJECT_ALLOCATED	= 0x800000,
	// New in VS2005
	//	COR_PRF_ENABLE_FUNCTION_ARGS	= 0x2000000,
	//	COR_PRF_ENABLE_FUNCTION_RETVAL	= 0x4000000,
	//  COR_PRF_ENABLE_FRAME_INFO	= 0x8000000,
	//  COR_PRF_ENABLE_STACK_SNAPSHOT	= 0x10000000,
	//  COR_PRF_USE_PROFILE_IMAGES	= 0x20000000,
	// End New in VS2005
	//COR_PRF_ALL	= 0x3fffffff,
	//COR_PRF_MONITOR_IMMUTABLE	= COR_PRF_MONITOR_CODE_TRANSITIONS | COR_PRF_MONITOR_REMOTING | COR_PRF_MONITOR_REMOTING_COOKIE | COR_PRF_MONITOR_REMOTING_ASYNC | COR_PRF_MONITOR_GC | COR_PRF_ENABLE_REJIT | COR_PRF_ENABLE_INPROC_DEBUGGING | COR_PRF_ENABLE_JIT_MAPS | COR_PRF_DISABLE_OPTIMIZATIONS | COR_PRF_DISABLE_INLINING | COR_PRF_ENABLE_OBJECT_ALLOCATED | COR_PRF_ENABLE_FUNCTION_ARGS | COR_PRF_ENABLE_FUNCTION_RETVAL | COR_PRF_ENABLE_FRAME_INFO | COR_PRF_ENABLE_STACK_SNAPSHOT | COR_PRF_USE_PROFILE_IMAGES

	// set the event mask 
	DWORD eventMask = (DWORD)(COR_PRF_MONITOR_JIT_COMPILATION | COR_PRF_MONITOR_MODULE_LOADS | COR_PRF_MONITOR_ENTERLEAVE | COR_PRF_ENABLE_FUNCTION_ARGS | COR_PRF_ENABLE_REJIT);
	return pCorProfilerInfo->SetEventMask(eventMask);
}

// this function simply forwards the FunctionEnter call the global profiler object
void __stdcall FunctionEnterGlobal(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_INFO *argInfo)
{
	// make sure the global reference to our profiler is valid
	if (g_pICorProfilerCallback != NULL)
		g_pICorProfilerCallback->Enter(functionID, clientData, frameInfo, argInfo);
}

// this function is called by the CLR when a function has been entered
void _declspec(naked) FunctionEnterNaked(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo)
{
	__asm
	{
		push    ebp                 // Create a standard frame
			mov     ebp, esp
			pushad                      // Preserve all registers

			mov     eax, [ebp + 0x14]      // argumentInfo
			push    eax
			mov     ecx, [ebp + 0x10]      // func
			push    ecx
			mov     edx, [ebp + 0x0C]      // clientData
			push    edx
			mov     eax, [ebp + 0x08]      // functionID
			push    eax
			call    FunctionEnterGlobal

			popad                       // Restore all registers
			pop     ebp                 // Restore EBP
			ret     16
	}
}

// this function simply forwards the FunctionLeave call the global profiler object
void __stdcall FunctionLeaveGlobal(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_RANGE *retvalRange)
{
	// make sure the global reference to our profiler is valid
	if (g_pICorProfilerCallback != NULL)
		g_pICorProfilerCallback->Leave(functionID, clientData, frameInfo, retvalRange);
}

// this function is called by the CLR when a function is exiting
void _declspec(naked) FunctionLeaveNaked(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_RANGE *retvalRange)
{
	__asm
	{
		push    ebp                 // Create a standard frame
			mov     ebp, esp
			pushad                      // Preserve all registers

			mov     eax, [ebp + 0x14]      // argumentInfo
			push    eax
			mov     ecx, [ebp + 0x10]      // func
			push    ecx
			mov     edx, [ebp + 0x0C]      // clientData
			push    edx
			mov     eax, [ebp + 0x08]      // functionID
			push    eax
			call    FunctionLeaveGlobal

			popad                       // Restore all registers
			pop     ebp                 // Restore EBP
			ret     16
	}
}

// this function simply forwards the FunctionLeave call the global profiler object
void __stdcall FunctionTailcallGlobal(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo)
{
	if (g_pICorProfilerCallback != NULL)
		g_pICorProfilerCallback->Tailcall(functionID, clientData, frameInfo);
}

// this function is called by the CLR when a tailcall occurs.  A tailcall occurs when the 
// last action of a method is a call to another method.
void _declspec(naked) FunctionTailcallNaked(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO func)
{
	__asm
	{
		push    ebp                 // Create a standard frame
			mov     ebp, esp
			pushad                      // Preserve all registers

			mov     eax, [ebp + 0x14]      // argumentInfo
			push    eax
			mov     ecx, [ebp + 0x10]      // func
			push    ecx
			mov     edx, [ebp + 0x0C]      // clientData
			push    edx
			mov     eax, [ebp + 0x08]      // functionID
			push    eax
			call    FunctionTailcallGlobal

			popad                       // Restore all registers
			pop     ebp                 // Restore EBP
			ret     16
	}
}

HRESULT STDMETHODCALLTYPE CProfilerInterface::Initialize(
	/* [in] */ IUnknown *pICorProfilerInfoUnk)
{
	// log that we are initializing
	Log_Info("Initializing...");
	g_pICorProfilerCallback = this;

	// get the ICorProfilerInfo interface
	HRESULT hr = pICorProfilerInfoUnk->QueryInterface(IID_ICorProfilerInfo, (LPVOID*)&pCorProfilerInfo);
	if (FAILED(hr))
		return E_FAIL;
	// determine if this object implements ICorProfilerInfo2
	hr = pICorProfilerInfoUnk->QueryInterface(IID_ICorProfilerInfo2, (LPVOID*)&pCorProfilerInfo2);
	if (FAILED(hr))
	{
		// we still want to work if this call fails, might be an older .NET version
		pCorProfilerInfo2.p = NULL;
		Log_Error("Error setting the enter, leave and tailcall hooks");
	}
	else
	{
		Log_Error("Successfully initialized profiling");
	}

	// set the enter, leave and tailcall hooks
	if (pCorProfilerInfo2.p == NULL)
	{
		// note that we are casting our functions to the definitions for the callbacks
		hr = pCorProfilerInfo->SetEnterLeaveFunctionHooks((FunctionEnter*)&FunctionEnterNaked, (FunctionLeave*)&FunctionLeaveNaked, (FunctionTailcall*)&FunctionTailcallNaked);
		if (SUCCEEDED(hr))
			hr = pCorProfilerInfo->SetFunctionIDMapper((FunctionIDMapper*)&FunctionMapper);
	}
	else
	{
		hr = pCorProfilerInfo2->SetEnterLeaveFunctionHooks2((FunctionEnter2*)&FunctionEnterNaked, (FunctionLeave2*)&FunctionLeaveNaked, (FunctionTailcall2*)&FunctionTailcallNaked);
		if (SUCCEEDED(hr))
			hr = pCorProfilerInfo2->SetFunctionIDMapper(FunctionMapper);
	}

	SetEvent();

	return S_OK;
}

// this function is called by the CLR when a function has been mapped to an ID
UINT_PTR CProfilerInterface::FunctionMapper(FunctionID functionID, BOOL *pbHookFunction)
{
	// make sure the global reference to our profiler is valid.  Forward this
	// call to our profiler object
	if (g_pICorProfilerCallback != NULL)
		g_pICorProfilerCallback->MapFunction(functionID);

	// we must return the function ID passed as a parameter
	return (UINT_PTR)functionID;
}

// the static function called by .Net when a function has been mapped to an ID
void CProfilerInterface::MapFunction(FunctionID functionID)
{

}

// ----  CALLBACK HANDLER FUNCTIONS ------------------

// our real handler for FunctionLeave notification
void CProfilerInterface::Leave(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_RANGE *argumentRange)
{
}

// our real handler for the FunctionTailcall notification
void CProfilerInterface::Tailcall(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo)
{
}


HRESULT CProfilerInterface::GetFullMethodName(FunctionID functionID, LPWSTR wszMethod, int cMethod)
{
	return Util::GetFullMethodName(pCorProfilerInfo2, functionID, wszMethod, cMethod);
}