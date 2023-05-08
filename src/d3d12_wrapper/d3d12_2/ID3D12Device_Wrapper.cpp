#include "pch.h"
#include "ID3D12Device_Wrapper.h"


ID3D12Device_Wrapper::ID3D12Device_Wrapper(Microsoft::WRL::ComPtr<ID3D12Device> object)
{
    this->object = object;
}

D3D12_RESOURCE_ALLOCATION_INFO ID3D12Device_Wrapper::GetResourceAllocationInfo(
	_In_  UINT visibleMask,
	_In_  UINT numResourceDescs,
	_In_reads_(numResourceDescs)  const D3D12_RESOURCE_DESC* pResourceDescs)
{
    D3D12_RESOURCE_ALLOCATION_INFO resource_info = object->GetResourceAllocationInfo(visibleMask, numResourceDescs, pResourceDescs);
    resource_info.SizeInBytes = resource_info.SizeInBytes * 8;

    return resource_info;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandQueue(
    _In_  const D3D12_COMMAND_QUEUE_DESC* pDesc,
    REFIID riid,
    _COM_Outptr_  void** ppCommandQueue)
{
    return object->CreateCommandQueue(pDesc, riid, ppCommandQueue);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateDescriptorHeap(
    _In_  const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
    REFIID riid,
    _COM_Outptr_  void** ppvHeap)
{
    return object->CreateDescriptorHeap(pDescriptorHeapDesc, riid, ppvHeap);
}

UINT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetDescriptorHandleIncrementSize(
    _In_  D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    return object->GetDescriptorHandleIncrementSize(DescriptorHeapType);
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateRenderTargetView(
    _In_opt_  ID3D12Resource* pResource,
    _In_opt_  const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
    _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) 
{
    return object->CreateRenderTargetView(pResource, pDesc, DestDescriptor);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandAllocator(
    _In_  D3D12_COMMAND_LIST_TYPE type,
    REFIID riid,
    _COM_Outptr_  void** ppCommandAllocator) 

{
    return object->CreateCommandAllocator(type, riid, ppCommandAllocator);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateRootSignature(
    _In_  UINT nodeMask,
    _In_reads_(blobLengthInBytes)  const void* pBlobWithRootSignature,
    _In_  SIZE_T blobLengthInBytes,
    REFIID riid,
    _COM_Outptr_  void** ppvRootSignature) 
{
    return object->CreateRootSignature(nodeMask, pBlobWithRootSignature, blobLengthInBytes, riid, ppvRootSignature);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateGraphicsPipelineState(
    _In_  const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    _COM_Outptr_  void** ppPipelineState) 
{
    return object->CreateGraphicsPipelineState(pDesc, riid, ppPipelineState);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandList(
    _In_  UINT nodeMask,
    _In_  D3D12_COMMAND_LIST_TYPE type,
    _In_  ID3D12CommandAllocator* pCommandAllocator,
    _In_opt_  ID3D12PipelineState* pInitialState,
    REFIID riid,
    _COM_Outptr_  void** ppCommandList) 
{
    return object->CreateCommandList(nodeMask, type, pCommandAllocator, pInitialState, riid, ppCommandList);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommittedResource(
    _In_  const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    _In_  const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    _In_opt_  const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riidResource,
    _COM_Outptr_opt_  void** ppvResource) 
{
    return object->CreateCommittedResource(pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, riidResource, ppvResource);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateFence(
    UINT64 InitialValue,
    D3D12_FENCE_FLAGS Flags,
    REFIID riid,
    _COM_Outptr_  void** ppFence) 
{
    return object->CreateFence(InitialValue, Flags, riid, ppFence);
}

///======= other method
UINT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetNodeCount(void)
{
    return object->GetNodeCount();
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateComputePipelineState(
    _In_  const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    _COM_Outptr_  void** ppPipelineState)
{
    return object->CreateComputePipelineState(pDesc, riid, ppPipelineState);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CheckFeatureSupport(
    D3D12_FEATURE Feature,
    _Inout_updates_bytes_(FeatureSupportDataSize)  void* pFeatureSupportData,
    UINT FeatureSupportDataSize) 
{
    return object->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize);
}


void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateConstantBufferView(
    _In_opt_  const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
    _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    return object->CreateConstantBufferView(pDesc, DestDescriptor);
}
void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateShaderResourceView(
    _In_opt_  ID3D12Resource* pResource,
    _In_opt_  const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
    _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    return object->CreateShaderResourceView(pResource, pDesc, DestDescriptor);
}
void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateUnorderedAccessView(
    _In_opt_  ID3D12Resource* pResource,
    _In_opt_  ID3D12Resource* pCounterResource,
    _In_opt_  const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
    _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    return object->CreateUnorderedAccessView(pResource, pCounterResource, pDesc, DestDescriptor);
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateDepthStencilView(
    _In_opt_  ID3D12Resource* pResource,
    _In_opt_  const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
    _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    return object->CreateDepthStencilView(pResource, pDesc, DestDescriptor);
}
void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateSampler(
    _In_  const D3D12_SAMPLER_DESC* pDesc,
    _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    return object->CreateSampler(pDesc, DestDescriptor);
}
void STDMETHODCALLTYPE ID3D12Device_Wrapper::CopyDescriptors(
    _In_  UINT NumDestDescriptorRanges,
    _In_reads_(NumDestDescriptorRanges)  const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
    _In_reads_opt_(NumDestDescriptorRanges)  const UINT* pDestDescriptorRangeSizes,
    _In_  UINT NumSrcDescriptorRanges,
    _In_reads_(NumSrcDescriptorRanges)  const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
    _In_reads_opt_(NumSrcDescriptorRanges)  const UINT* pSrcDescriptorRangeSizes,
    _In_  D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    return object->CopyDescriptors(NumDestDescriptorRanges, pDestDescriptorRangeStarts, pDestDescriptorRangeSizes,
        NumSrcDescriptorRanges, pSrcDescriptorRangeStarts, pSrcDescriptorRangeSizes, DescriptorHeapsType
    );
}
void STDMETHODCALLTYPE ID3D12Device_Wrapper::CopyDescriptorsSimple(
    _In_  UINT NumDescriptors,
    _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    _In_  D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    _In_  D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    return object->CopyDescriptorsSimple(NumDescriptors, DestDescriptorRangeStart, SrcDescriptorRangeStart, DescriptorHeapsType);
}

D3D12_HEAP_PROPERTIES STDMETHODCALLTYPE ID3D12Device_Wrapper::GetCustomHeapProperties(
    _In_  UINT nodeMask,
    D3D12_HEAP_TYPE heapType)
{
    return object->GetCustomHeapProperties(nodeMask, heapType);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateHeap(
    _In_  const D3D12_HEAP_DESC* pDesc,
    REFIID riid,
    _COM_Outptr_opt_  void** ppvHeap)
{
    return object->CreateHeap(pDesc, riid, ppvHeap);
}
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreatePlacedResource(
    _In_  ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    _In_  const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    _In_opt_  const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    _COM_Outptr_opt_  void** ppvResource)
{
    return object->CreatePlacedResource(pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource);
}
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateReservedResource(
    _In_  const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    _In_opt_  const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    _COM_Outptr_opt_  void** ppvResource)
{
    return object->CreateReservedResource(pDesc, InitialState, pOptimizedClearValue, riid, ppvResource);
}
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateSharedHandle(
    _In_  ID3D12DeviceChild* pObject,
    _In_opt_  const SECURITY_ATTRIBUTES* pAttributes,
    DWORD Access,
    _In_opt_  LPCWSTR Name,
    _Out_  HANDLE* pHandle)
{
    return object->CreateSharedHandle(pObject, pAttributes, Access, Name, pHandle);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::OpenSharedHandle(
    _In_  HANDLE NTHandle,
    REFIID riid,
    _COM_Outptr_opt_  void** ppvObj)
{
    return object->OpenSharedHandle(NTHandle, riid, ppvObj);
}
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::OpenSharedHandleByName(
    _In_  LPCWSTR Name,
    DWORD Access,
    /* [annotation][out] */
    _Out_  HANDLE* pNTHandle)
{
    return object->OpenSharedHandleByName(Name, Access, pNTHandle);
}
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::MakeResident(
    UINT NumObjects,
    _In_reads_(NumObjects)  ID3D12Pageable* const* ppObjects)
{
    return object->MakeResident(NumObjects, ppObjects);
}
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::Evict(
    UINT NumObjects,
    _In_reads_(NumObjects)  ID3D12Pageable* const* ppObjects)
{
    return object->Evict(NumObjects, ppObjects);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetDeviceRemovedReason(void)
{
    return object->GetDeviceRemovedReason();
}
void STDMETHODCALLTYPE ID3D12Device_Wrapper::GetCopyableFootprints(
    _In_  const D3D12_RESOURCE_DESC* pResourceDesc,
    _In_range_(0, D3D12_REQ_SUBRESOURCES)  UINT FirstSubresource,
    _In_range_(0, D3D12_REQ_SUBRESOURCES - FirstSubresource)  UINT NumSubresources,
    UINT64 BaseOffset,
    _Out_writes_opt_(NumSubresources)  D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    _Out_writes_opt_(NumSubresources)  UINT* pNumRows,
    _Out_writes_opt_(NumSubresources)  UINT64* pRowSizeInBytes,
    _Out_opt_  UINT64* pTotalBytes)
{
    return object->GetCopyableFootprints(pResourceDesc, FirstSubresource, NumSubresources,
        BaseOffset, pLayouts, pNumRows, pRowSizeInBytes, pTotalBytes
    );
}
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateQueryHeap(
    _In_  const D3D12_QUERY_HEAP_DESC* pDesc,
    REFIID riid,
    _COM_Outptr_opt_  void** ppvHeap)
{
    return object->CreateQueryHeap(pDesc, riid, ppvHeap);
}
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::SetStablePowerState(
    BOOL Enable)
{
    return object->SetStablePowerState(Enable);
}
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandSignature(
    _In_  const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
    _In_opt_  ID3D12RootSignature* pRootSignature,
    REFIID riid,
    _COM_Outptr_opt_  void** ppvCommandSignature)
{
    return object->CreateCommandSignature(pDesc, pRootSignature, riid, ppvCommandSignature);
}
void STDMETHODCALLTYPE ID3D12Device_Wrapper::GetResourceTiling(
    _In_  ID3D12Resource* pTiledResource,
    _Out_opt_  UINT* pNumTilesForEntireResource,
    _Out_opt_  D3D12_PACKED_MIP_INFO* pPackedMipDesc,
    _Out_opt_  D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
    _Inout_opt_  UINT* pNumSubresourceTilings,
    _In_  UINT FirstSubresourceTilingToGet,
    _Out_writes_(*pNumSubresourceTilings)  D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips)
{
    return object->GetResourceTiling(pTiledResource, pNumTilesForEntireResource, pPackedMipDesc,
        pStandardTileShapeForNonPackedMips, pNumSubresourceTilings, FirstSubresourceTilingToGet,
        pSubresourceTilingsForNonPackedMips
    );
}
LUID STDMETHODCALLTYPE ID3D12Device_Wrapper::GetAdapterLuid(void)
{
    return object->GetAdapterLuid();
}

// ----method from ID3D12Object

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetPrivateData(
    _In_  REFGUID guid,
    _Inout_  UINT* pDataSize,
    _Out_writes_bytes_opt_(*pDataSize)  void* pData)
{
    return object->GetPrivateData(guid, pDataSize, pData);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::SetPrivateData(
    _In_  REFGUID guid,
    _In_  UINT DataSize,
    _In_reads_bytes_opt_(DataSize)  const void* pData)
{
    return object->SetPrivateData(guid, DataSize, pData);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::SetPrivateDataInterface(
    _In_  REFGUID guid,
    _In_opt_  const IUnknown* pData)
{
    return object->SetPrivateDataInterface(guid, pData);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::SetName(
    _In_z_  LPCWSTR Name)
{
    return object->SetName(Name);
}

// ----method from IUnkown
HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::QueryInterface(
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject)
{
    return object->QueryInterface(riid, ppvObject);
}

ULONG STDMETHODCALLTYPE ID3D12Device_Wrapper::AddRef(void)
{
    return object->AddRef();
}

ULONG STDMETHODCALLTYPE ID3D12Device_Wrapper::Release(void)
{
    return object->Release();
}