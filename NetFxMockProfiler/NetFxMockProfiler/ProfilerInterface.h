// ProfilerInterface.h : Declaration of the CProfilerInterface

#pragma once
#include "resource.h"       // main symbols
#include "NetFxMockProfiler_i.h"
#include <CorHdr.h>
#include <cor.h>
#include <corprof.h>

#pragma  comment(lib,"corguids.lib")

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CProfilerInterface

class ATL_NO_VTABLE CProfilerInterface :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CProfilerInterface, &CLSID_ProfilerInterface>,
	public IDispatchImpl<IProfilerInterface, &IID_IProfilerInterface, &LIBID_NetFxMockProfilerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ICorProfilerCallback4
{
public:
	CProfilerInterface()
	{
	}
	~CProfilerInterface()
	{

	}

	DECLARE_REGISTRY_RESOURCEID(106)


	BEGIN_COM_MAP(CProfilerInterface)
		COM_INTERFACE_ENTRY(IProfilerInterface)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ICorProfilerCallback)
		COM_INTERFACE_ENTRY(ICorProfilerCallback2)
		COM_INTERFACE_ENTRY(ICorProfilerCallback4)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	HRESULT STDMETHODCALLTYPE Initialize(
		/* [in] */ IUnknown *pICorProfilerInfoUnk) { return S_OK; }

	HRESULT STDMETHODCALLTYPE Shutdown(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE AppDomainCreationStarted(
		/* [in] */ AppDomainID appDomainId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE AppDomainCreationFinished(
		/* [in] */ AppDomainID appDomainId,
		/* [in] */ HRESULT hrStatus) { return S_OK; }

	HRESULT STDMETHODCALLTYPE AppDomainShutdownStarted(
		/* [in] */ AppDomainID appDomainId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE AppDomainShutdownFinished(
		/* [in] */ AppDomainID appDomainId,
		/* [in] */ HRESULT hrStatus) { return S_OK; }

	HRESULT STDMETHODCALLTYPE AssemblyLoadStarted(
		/* [in] */ AssemblyID assemblyId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE AssemblyLoadFinished(
		/* [in] */ AssemblyID assemblyId,
		/* [in] */ HRESULT hrStatus) { return S_OK; }

	HRESULT STDMETHODCALLTYPE AssemblyUnloadStarted(
		/* [in] */ AssemblyID assemblyId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE AssemblyUnloadFinished(
		/* [in] */ AssemblyID assemblyId,
		/* [in] */ HRESULT hrStatus) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ModuleLoadStarted(
		/* [in] */ ModuleID moduleId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ModuleLoadFinished(
		/* [in] */ ModuleID moduleId,
		/* [in] */ HRESULT hrStatus) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ModuleUnloadStarted(
		/* [in] */ ModuleID moduleId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ModuleUnloadFinished(
		/* [in] */ ModuleID moduleId,
		/* [in] */ HRESULT hrStatus) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ModuleAttachedToAssembly(
		/* [in] */ ModuleID moduleId,
		/* [in] */ AssemblyID AssemblyId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ClassLoadStarted(
		/* [in] */ ClassID classId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ClassLoadFinished(
		/* [in] */ ClassID classId,
		/* [in] */ HRESULT hrStatus) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ClassUnloadStarted(
		/* [in] */ ClassID classId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ClassUnloadFinished(
		/* [in] */ ClassID classId,
		/* [in] */ HRESULT hrStatus) { return S_OK; }

	HRESULT STDMETHODCALLTYPE FunctionUnloadStarted(
		/* [in] */ FunctionID functionId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE JITCompilationStarted(
		/* [in] */ FunctionID functionId,
		/* [in] */ BOOL fIsSafeToBlock) { return S_OK; }

	HRESULT STDMETHODCALLTYPE JITCompilationFinished(
		/* [in] */ FunctionID functionId,
		/* [in] */ HRESULT hrStatus,
		/* [in] */ BOOL fIsSafeToBlock) { return S_OK; }

	HRESULT STDMETHODCALLTYPE JITCachedFunctionSearchStarted(
		/* [in] */ FunctionID functionId,
		/* [out] */ BOOL *pbUseCachedFunction) { return S_OK; }

	HRESULT STDMETHODCALLTYPE JITCachedFunctionSearchFinished(
		/* [in] */ FunctionID functionId,
		/* [in] */ COR_PRF_JIT_CACHE result) { return S_OK; }

	HRESULT STDMETHODCALLTYPE JITFunctionPitched(
		/* [in] */ FunctionID functionId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE JITInlining(
		/* [in] */ FunctionID callerId,
		/* [in] */ FunctionID calleeId,
		/* [out] */ BOOL *pfShouldInline) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ThreadCreated(
		/* [in] */ ThreadID threadId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ThreadDestroyed(
		/* [in] */ ThreadID threadId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ThreadAssignedToOSThread(
		/* [in] */ ThreadID managedThreadId,
		/* [in] */ DWORD osThreadId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RemotingClientInvocationStarted(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RemotingClientSendingMessage(
		/* [in] */ GUID *pCookie,
		/* [in] */ BOOL fIsAsync) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RemotingClientReceivingReply(
		/* [in] */ GUID *pCookie,
		/* [in] */ BOOL fIsAsync) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RemotingClientInvocationFinished(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RemotingServerReceivingMessage(
		/* [in] */ GUID *pCookie,
		/* [in] */ BOOL fIsAsync) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RemotingServerInvocationStarted(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RemotingServerInvocationReturned(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RemotingServerSendingReply(
		/* [in] */ GUID *pCookie,
		/* [in] */ BOOL fIsAsync) { return S_OK; }

	HRESULT STDMETHODCALLTYPE UnmanagedToManagedTransition(
		/* [in] */ FunctionID functionId,
		/* [in] */ COR_PRF_TRANSITION_REASON reason) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ManagedToUnmanagedTransition(
		/* [in] */ FunctionID functionId,
		/* [in] */ COR_PRF_TRANSITION_REASON reason) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RuntimeSuspendStarted(
		/* [in] */ COR_PRF_SUSPEND_REASON suspendReason) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RuntimeSuspendFinished(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RuntimeSuspendAborted(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RuntimeResumeStarted(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RuntimeResumeFinished(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RuntimeThreadSuspended(
		/* [in] */ ThreadID threadId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RuntimeThreadResumed(
		/* [in] */ ThreadID threadId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE MovedReferences(
		/* [in] */ ULONG cMovedObjectIDRanges,
		/* [size_is][in] */ ObjectID oldObjectIDRangeStart[],
		/* [size_is][in] */ ObjectID newObjectIDRangeStart[],
		/* [size_is][in] */ ULONG cObjectIDRangeLength[]) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ObjectAllocated(
		/* [in] */ ObjectID objectId,
		/* [in] */ ClassID classId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ObjectsAllocatedByClass(
		/* [in] */ ULONG cClassCount,
		/* [size_is][in] */ ClassID classIds[],
		/* [size_is][in] */ ULONG cObjects[]) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ObjectReferences(
		/* [in] */ ObjectID objectId,
		/* [in] */ ClassID classId,
		/* [in] */ ULONG cObjectRefs,
		/* [size_is][in] */ ObjectID objectRefIds[]) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RootReferences(
		/* [in] */ ULONG cRootRefs,
		/* [size_is][in] */ ObjectID rootRefIds[]) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionThrown(
		/* [in] */ ObjectID thrownObjectId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionSearchFunctionEnter(
		/* [in] */ FunctionID functionId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionSearchFunctionLeave(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionSearchFilterEnter(
		/* [in] */ FunctionID functionId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionSearchFilterLeave(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionSearchCatcherFound(
		/* [in] */ FunctionID functionId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionOSHandlerEnter(
		/* [in] */ UINT_PTR __unused) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionOSHandlerLeave(
		/* [in] */ UINT_PTR __unused) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionUnwindFunctionEnter(
		/* [in] */ FunctionID functionId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionUnwindFunctionLeave(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionUnwindFinallyEnter(
		/* [in] */ FunctionID functionId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionUnwindFinallyLeave(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionCatcherEnter(
		/* [in] */ FunctionID functionId,
		/* [in] */ ObjectID objectId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionCatcherLeave(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE COMClassicVTableCreated(
		/* [in] */ ClassID wrappedClassId,
		/* [in] */ REFGUID implementedIID,
		/* [in] */ void *pVTable,
		/* [in] */ ULONG cSlots) { return S_OK; }

	HRESULT STDMETHODCALLTYPE COMClassicVTableDestroyed(
		/* [in] */ ClassID wrappedClassId,
		/* [in] */ REFGUID implementedIID,
		/* [in] */ void *pVTable) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionCLRCatcherFound(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ExceptionCLRCatcherExecute(void) { return S_OK; }

	// call back 2
	HRESULT STDMETHODCALLTYPE ThreadNameChanged(
		/* [in] */ ThreadID threadId,
		/* [in] */ ULONG cchName,
		/* [annotation][in] */
		_In_reads_opt_(cchName)  WCHAR name[]) { return S_OK; }

	HRESULT STDMETHODCALLTYPE GarbageCollectionStarted(
		/* [in] */ int cGenerations,
		/* [size_is][in] */ BOOL generationCollected[],
		/* [in] */ COR_PRF_GC_REASON reason) { return S_OK; }

	HRESULT STDMETHODCALLTYPE SurvivingReferences(
		/* [in] */ ULONG cSurvivingObjectIDRanges,
		/* [size_is][in] */ ObjectID objectIDRangeStart[],
		/* [size_is][in] */ ULONG cObjectIDRangeLength[]) { return S_OK; }

	HRESULT STDMETHODCALLTYPE GarbageCollectionFinished(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE FinalizeableObjectQueued(
		/* [in] */ DWORD finalizerFlags,
		/* [in] */ ObjectID objectID) { return S_OK; }

	HRESULT STDMETHODCALLTYPE RootReferences2(
		/* [in] */ ULONG cRootRefs,
		/* [size_is][in] */ ObjectID rootRefIds[],
		/* [size_is][in] */ COR_PRF_GC_ROOT_KIND rootKinds[],
		/* [size_is][in] */ COR_PRF_GC_ROOT_FLAGS rootFlags[],
		/* [size_is][in] */ UINT_PTR rootIds[]) { return S_OK; }

	HRESULT STDMETHODCALLTYPE HandleCreated(
		/* [in] */ GCHandleID handleId,
		/* [in] */ ObjectID initialObjectId) { return S_OK; }

	HRESULT STDMETHODCALLTYPE HandleDestroyed(
		/* [in] */ GCHandleID handleId) { return S_OK; }

	// callback3
	HRESULT STDMETHODCALLTYPE InitializeForAttach(
		/* [in] */ IUnknown *pCorProfilerInfoUnk,
		/* [in] */ void *pvClientData,
		/* [in] */ UINT cbClientData) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ProfilerAttachComplete(void) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ProfilerDetachSucceeded(void) { return S_OK; }

	// call back 4
	HRESULT STDMETHODCALLTYPE ReJITCompilationStarted(
		/* [in] */ FunctionID functionId,
		/* [in] */ ReJITID rejitId,
		/* [in] */ BOOL fIsSafeToBlock) { return S_OK; }

	HRESULT STDMETHODCALLTYPE GetReJITParameters(
		/* [in] */ ModuleID moduleId,
		/* [in] */ mdMethodDef methodId,
		/* [in] */ ICorProfilerFunctionControl *pFunctionControl) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ReJITCompilationFinished(
		/* [in] */ FunctionID functionId,
		/* [in] */ ReJITID rejitId,
		/* [in] */ HRESULT hrStatus,
		/* [in] */ BOOL fIsSafeToBlock) { return S_OK; }

	HRESULT STDMETHODCALLTYPE ReJITError(
		/* [in] */ ModuleID moduleId,
		/* [in] */ mdMethodDef methodId,
		/* [in] */ FunctionID functionId,
		/* [in] */ HRESULT hrStatus) { return S_OK; }

	HRESULT STDMETHODCALLTYPE MovedReferences2(
		/* [in] */ ULONG cMovedObjectIDRanges,
		/* [size_is][in] */ ObjectID oldObjectIDRangeStart[],
		/* [size_is][in] */ ObjectID newObjectIDRangeStart[],
		/* [size_is][in] */ SIZE_T cObjectIDRangeLength[]) { return S_OK; }

	HRESULT STDMETHODCALLTYPE SurvivingReferences2(
		/* [in] */ ULONG cSurvivingObjectIDRanges,
		/* [size_is][in] */ ObjectID objectIDRangeStart[],
		/* [size_is][in] */ SIZE_T cObjectIDRangeLength[]) { return S_OK; }

public:



};

OBJECT_ENTRY_AUTO(__uuidof(ProfilerInterface), CProfilerInterface)
