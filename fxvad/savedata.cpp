/*++

Copyright (c) 1997-2000  Microsoft Corporation All Rights Reserved

Module Name:

    savedata.cpp

Abstract:

    Implementation of MSVAD data saving class.

    To save the playback data to disk, this class maintains a circular data
    buffer, associated frame structures and worker items to save frames to
    disk.
    Each frame structure represents a portion of buffer. When that portion
    of frame is full, a workitem is scheduled to save it to disk.



--*/
#pragma warning (disable : 4127)
#pragma warning (disable : 26165)

#include <msvad.h>
#include "savedata.h"
#include <ntstrsafe.h>   // This is for using RtlStringcbPrintf

//=============================================================================
// Defines
//=============================================================================
#define RIFF_TAG                    0x46464952;
#define WAVE_TAG                    0x45564157;
#define FMT__TAG                    0x20746D66;
#define DATA_TAG                    0x61746164;

#define DEFAULT_FRAME_COUNT         2
#define DEFAULT_FRAME_SIZE          PAGE_SIZE * 4
#define DEFAULT_BUFFER_SIZE         DEFAULT_FRAME_SIZE * DEFAULT_FRAME_COUNT

#define DEFAULT_FILE_NAME           L"\\DosDevices\\C:\\STREAM"

#define MAX_WORKER_ITEM_COUNT       15

//=============================================================================
// Statics
//=============================================================================
ULONG CSaveData::m_ulStreamId = 0;

#pragma code_seg("PAGE")
//=============================================================================
// CSaveData
//=============================================================================

//=============================================================================
CSaveData::CSaveData()
:   m_pDataBuffer(NULL),
    m_FileHandle(NULL),
    m_ulFrameCount(DEFAULT_FRAME_COUNT),
    m_ulBufferSize(DEFAULT_BUFFER_SIZE),
    m_ulFrameSize(DEFAULT_FRAME_SIZE),
    m_ulBufferPtr(0),
    m_ulFramePtr(0),
    m_fFrameUsed(NULL),
    m_pFilePtr(NULL),
    m_fWriteDisabled(FALSE),
    m_bInitialized(FALSE)
{
} // CSaveData

//=============================================================================
CSaveData::~CSaveData()
{
} // CSaveData

//=============================================================================
void
CSaveData::DestroyWorkItems
(
    void
)
{
} // DestroyWorkItems

//=============================================================================
void
CSaveData::Disable
(
    BOOL                        fDisable
)
{
    UNREFERENCED_PARAMETER(fDisable);
} // Disable

//=============================================================================
NTSTATUS
CSaveData::FileClose(void)
{
    NTSTATUS                    ntStatus = STATUS_SUCCESS;
    return ntStatus;
} // FileClose

//=============================================================================
NTSTATUS
CSaveData::FileOpen
(
    IN  BOOL                    fOverWrite
)
{
    UNREFERENCED_PARAMETER(fOverWrite);

    NTSTATUS                    ntStatus = STATUS_SUCCESS;
    return ntStatus;
} // FileOpen

//=============================================================================
NTSTATUS
CSaveData::FileWrite
(
    _In_reads_bytes_(ulDataSize)    PBYTE   pData,
    _In_                            ULONG   ulDataSize
)
{
    UNREFERENCED_PARAMETER(pData);
    UNREFERENCED_PARAMETER(ulDataSize);

    NTSTATUS                    ntStatus = STATUS_SUCCESS;
    return ntStatus;
} // FileWrite

//=============================================================================
NTSTATUS
CSaveData::FileWriteHeader(void)
{
    NTSTATUS                    ntStatus = STATUS_SUCCESS;
    return ntStatus;
} // FileWriteHeader

NTSTATUS
CSaveData::SetDeviceObject
(
    IN  PDEVICE_OBJECT          DeviceObject
)
{
    ASSERT(DeviceObject);

    NTSTATUS                    ntStatus = STATUS_SUCCESS;
    
    m_pDeviceObject = DeviceObject;

    return ntStatus;
}

PDEVICE_OBJECT
CSaveData::GetDeviceObject
(
    void
)
{
    PAGED_CODE();

    return m_pDeviceObject;
}

#pragma code_seg()
//=============================================================================
PSAVEWORKER_PARAM
CSaveData::GetNewWorkItem
(
    void
)
{
    return NULL;
} // GetNewWorkItem
#pragma code_seg("PAGE")

//=============================================================================
NTSTATUS
CSaveData::Initialize
(
    void
)
{
    NTSTATUS    ntStatus = STATUS_SUCCESS;
    return ntStatus;
} // Initialize

//=============================================================================
NTSTATUS
CSaveData::InitializeWorkItems
(
    IN  PDEVICE_OBJECT          DeviceObject
)
{
    UNREFERENCED_PARAMETER(DeviceObject);

    NTSTATUS                    ntStatus = STATUS_SUCCESS;
    return ntStatus;
} // InitializeWorkItems

//=============================================================================

IO_WORKITEM_ROUTINE SaveFrameWorkerCallback;

VOID
SaveFrameWorkerCallback
(
    PDEVICE_OBJECT pDeviceObject, IN  PVOID  Context
)
{
    UNREFERENCED_PARAMETER(pDeviceObject);
    UNREFERENCED_PARAMETER(Context);
} // SaveFrameWorkerCallback

//=============================================================================
NTSTATUS
CSaveData::SetDataFormat
(
    IN PKSDATAFORMAT            pDataFormat
)
{
    UNREFERENCED_PARAMETER(pDataFormat);

    NTSTATUS                    ntStatus = STATUS_SUCCESS;
 
    return ntStatus;
} // SetDataFormat

//=============================================================================
void
CSaveData::ReadData
(
    _Inout_updates_bytes_all_(ulByteCount)  PBYTE   pBuffer,
    _In_                                    ULONG   ulByteCount
)
{
    UNREFERENCED_PARAMETER(pBuffer);
    UNREFERENCED_PARAMETER(ulByteCount);
} // ReadData

//=============================================================================
#pragma code_seg()
void
CSaveData::SaveFrame
(
    IN ULONG                    ulFrameNo,
    IN ULONG                    ulDataSize
)
{
    UNREFERENCED_PARAMETER(ulFrameNo);
    UNREFERENCED_PARAMETER(ulDataSize);
} // SaveFrame
#pragma code_seg("PAGE")
//=============================================================================
void
CSaveData::WaitAllWorkItems
(
    void
)
{
} // WaitAllWorkItems

#pragma code_seg()
//=============================================================================
void
CSaveData::WriteData
(
    _In_reads_bytes_(ulByteCount)   PBYTE   pBuffer,
    _In_                            ULONG   ulByteCount
)
{
    UNREFERENCED_PARAMETER(pBuffer);
    UNREFERENCED_PARAMETER(ulByteCount);
} // WriteData


