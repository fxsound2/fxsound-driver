/*++

Copyright (c) 1997-2000  Microsoft Corporation All Rights Reserved

Module Name:

    Common.h

Abstract:
    
    CAdapterCommon class declaration.

--*/

#ifndef _MSVAD_COMMON_H_
#define _MSVAD_COMMON_H_

//=============================================================================
// Defines
//=============================================================================

// {BA5C6084-5670-4BA5-B09C-35E5374AA0BE}
DEFINE_GUID(IID_IAdapterCommon,
    0xba5c6084, 0x5670, 0x4ba5, 0xb0, 0x9c, 0x35, 0xe5, 0x37, 0x4a, 0xa0, 0xbe);


//=============================================================================
// Interfaces
//=============================================================================

///////////////////////////////////////////////////////////////////////////////
// IAdapterCommon
//
DECLARE_INTERFACE_(IAdapterCommon, IUnknown)
{
    STDMETHOD_(NTSTATUS,        Init) 
    ( 
        THIS_
        IN  PDEVICE_OBJECT      DeviceObject 
    ) PURE;

    STDMETHOD_(PDEVICE_OBJECT,  GetDeviceObject)
    (
        THIS
    ) PURE;

    STDMETHOD_(VOID,            SetWaveServiceGroup) 
    ( 
        THIS_
        IN PSERVICEGROUP        ServiceGroup 
    ) PURE;

    STDMETHOD_(NTSTATUS,        InstantiateDevices)
    (
        THIS
    ) PURE;

    STDMETHOD_(NTSTATUS,        UninstantiateDevices)
    (
        THIS
    ) PURE;

    STDMETHOD_(NTSTATUS,        Plugin)
    (
        THIS
    ) PURE;

    STDMETHOD_(NTSTATUS,        Unplug)
    (
        THIS
    ) PURE;

    STDMETHOD_(PUNKNOWN *,      WavePortDriverDest) 
    ( 
        THIS 
    ) PURE;

    STDMETHOD_(BOOL,            bDevSpecificRead)
    (
        THIS_
    ) PURE;

    STDMETHOD_(VOID,            bDevSpecificWrite)
    (
        THIS_
        IN  BOOL                bDevSpecific
    );

    STDMETHOD_(INT,             iDevSpecificRead)
    (
        THIS_
    ) PURE;

    STDMETHOD_(VOID,            iDevSpecificWrite)
    (
        THIS_
        IN  INT                 iDevSpecific
    );

    STDMETHOD_(UINT,            uiDevSpecificRead)
    (
        THIS_
    ) PURE;

    STDMETHOD_(VOID,            uiDevSpecificWrite)
    (
        THIS_
        IN  UINT                uiDevSpecific
    );

    STDMETHOD_(BOOL,            MixerMuteRead)
    (
        THIS_
        IN  ULONG               Index
    ) PURE;

    STDMETHOD_(VOID,            MixerMuteWrite)
    (
        THIS_
        IN  ULONG               Index,
        IN  BOOL                Value
    );

    STDMETHOD_(ULONG,           MixerMuxRead)
    (
        THIS
    );

    STDMETHOD_(VOID,            MixerMuxWrite)
    (
        THIS_
        IN  ULONG               Index
    );

    STDMETHOD_(LONG,            MixerVolumeRead) 
    ( 
        THIS_
        IN  ULONG               Index,
        IN  LONG                Channel
    ) PURE;

    STDMETHOD_(VOID,            MixerVolumeWrite) 
    ( 
        THIS_
        IN  ULONG               Index,
        IN  LONG                Channel,
        IN  LONG                Value 
    ) PURE;

    STDMETHOD_(VOID,            MixerReset) 
    ( 
        THIS 
    ) PURE;

    STDMETHOD_(BOOL,            IsInstantiated) 
    ( 
        THIS 
    ) PURE;

    STDMETHOD_(BOOL,            IsPluggedIn) 
    ( 
        THIS 
    ) PURE;

    STDMETHOD_(NTSTATUS,        SetInstantiateWorkItem)
    (
        THIS_
        _In_ __drv_aliasesMem   PIO_WORKITEM    WorkItem
    ) PURE;

    STDMETHOD_(NTSTATUS,        FreeInstantiateWorkItem)
    (
        THIS_
    ) PURE;
};
typedef IAdapterCommon *PADAPTERCOMMON;

//=============================================================================
// Function Prototypes
//=============================================================================
NTSTATUS
NewAdapterCommon
( 
    OUT PUNKNOWN *              Unknown,
    IN  REFCLSID,
    IN  PUNKNOWN                UnknownOuter OPTIONAL,
    _When_((PoolType & NonPagedPoolMustSucceed) != 0,
       __drv_reportError("Must succeed pool allocations are forbidden. "
			 "Allocation failures cause a system crash"))
    IN  POOL_TYPE               PoolType 
);

#endif  //_COMMON_H_

