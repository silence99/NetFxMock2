// dllmain.h : Declaration of module class.

class CNetFxMockProfilerModule : public ATL::CAtlDllModuleT< CNetFxMockProfilerModule >
{
public :
	DECLARE_LIBID(LIBID_NetFxMockProfilerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_NETFXMOCKPROFILER, "{9338A0A4-BBF3-45DF-A613-296731D44694}")
};

extern class CNetFxMockProfilerModule _AtlModule;
