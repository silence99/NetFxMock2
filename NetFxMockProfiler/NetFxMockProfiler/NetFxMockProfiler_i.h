

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Dec 05 23:02:56 2018
 */
/* Compiler settings for NetFxMockProfiler.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __NetFxMockProfiler_i_h__
#define __NetFxMockProfiler_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IProfilerInterface_FWD_DEFINED__
#define __IProfilerInterface_FWD_DEFINED__
typedef interface IProfilerInterface IProfilerInterface;

#endif 	/* __IProfilerInterface_FWD_DEFINED__ */


#ifndef __ProfilerInterface_FWD_DEFINED__
#define __ProfilerInterface_FWD_DEFINED__

#ifdef __cplusplus
typedef class ProfilerInterface ProfilerInterface;
#else
typedef struct ProfilerInterface ProfilerInterface;
#endif /* __cplusplus */

#endif 	/* __ProfilerInterface_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IProfilerInterface_INTERFACE_DEFINED__
#define __IProfilerInterface_INTERFACE_DEFINED__

/* interface IProfilerInterface */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IProfilerInterface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3ba25e61-9db1-4ca3-8f51-5fc8427cea82")
    IProfilerInterface : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IProfilerInterfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProfilerInterface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProfilerInterface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProfilerInterface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProfilerInterface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProfilerInterface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProfilerInterface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProfilerInterface * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IProfilerInterfaceVtbl;

    interface IProfilerInterface
    {
        CONST_VTBL struct IProfilerInterfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProfilerInterface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProfilerInterface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProfilerInterface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProfilerInterface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IProfilerInterface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IProfilerInterface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IProfilerInterface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProfilerInterface_INTERFACE_DEFINED__ */



#ifndef __NetFxMockProfilerLib_LIBRARY_DEFINED__
#define __NetFxMockProfilerLib_LIBRARY_DEFINED__

/* library NetFxMockProfilerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_NetFxMockProfilerLib;

EXTERN_C const CLSID CLSID_ProfilerInterface;

#ifdef __cplusplus

class DECLSPEC_UUID("fd9efb8f-b2c5-46b9-bd30-4cbf8202e033")
ProfilerInterface;
#endif
#endif /* __NetFxMockProfilerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


