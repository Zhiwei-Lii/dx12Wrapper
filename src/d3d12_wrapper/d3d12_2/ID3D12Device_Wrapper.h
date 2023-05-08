#pragma once
#include <d3d12.h>
#include <Windows.h>
#include <wrl.h>



class ID3D12Device_Wrapper : public ID3D12Device
{

public:
    Microsoft::WRL::ComPtr<ID3D12Device> object;

    ID3D12Device_Wrapper(Microsoft::WRL::ComPtr<ID3D12Device> object);

	D3D12_RESOURCE_ALLOCATION_INFO  GetResourceAllocationInfo(
		_In_  UINT visibleMask,
		_In_  UINT numResourceDescs,
		_In_reads_(numResourceDescs)  const D3D12_RESOURCE_DESC* pResourceDescs
	) override;

    HRESULT STDMETHODCALLTYPE CreateCommandQueue(
        _In_  const D3D12_COMMAND_QUEUE_DESC* pDesc,
        REFIID riid,
        _COM_Outptr_  void** ppCommandQueue) override;

    HRESULT STDMETHODCALLTYPE CreateDescriptorHeap(
        _In_  const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
        REFIID riid,
        _COM_Outptr_  void** ppvHeap) override;

    UINT STDMETHODCALLTYPE GetDescriptorHandleIncrementSize(
        _In_  D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType) override;

    void STDMETHODCALLTYPE CreateRenderTargetView(
        _In_opt_  ID3D12Resource* pResource,
        _In_opt_  const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
        _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

    HRESULT STDMETHODCALLTYPE CreateCommandAllocator(
        _In_  D3D12_COMMAND_LIST_TYPE type,
        REFIID riid,
        _COM_Outptr_  void** ppCommandAllocator) override;

    HRESULT STDMETHODCALLTYPE CreateRootSignature(
        _In_  UINT nodeMask,
        _In_reads_(blobLengthInBytes)  const void* pBlobWithRootSignature,
        _In_  SIZE_T blobLengthInBytes,
        REFIID riid,
        _COM_Outptr_  void** ppvRootSignature) override;

    HRESULT STDMETHODCALLTYPE CreateGraphicsPipelineState(
        _In_  const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        _COM_Outptr_  void** ppPipelineState) override;

    HRESULT STDMETHODCALLTYPE CreateCommandList(
        _In_  UINT nodeMask,
        _In_  D3D12_COMMAND_LIST_TYPE type,
        _In_  ID3D12CommandAllocator* pCommandAllocator,
        _In_opt_  ID3D12PipelineState* pInitialState,
        REFIID riid,
        _COM_Outptr_  void** ppCommandList) override;

    HRESULT STDMETHODCALLTYPE CreateCommittedResource(
        _In_  const D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        _In_  const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        _In_opt_  const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riidResource,
        _COM_Outptr_opt_  void** ppvResource) override;

    HRESULT STDMETHODCALLTYPE CreateFence(
        UINT64 InitialValue,
        D3D12_FENCE_FLAGS Flags,
        REFIID riid,
        _COM_Outptr_  void** ppFence) override;

    // ----other method

    UINT STDMETHODCALLTYPE GetNodeCount(void) override;


    HRESULT STDMETHODCALLTYPE CreateComputePipelineState(
        _In_  const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        _COM_Outptr_  void** ppPipelineState) override;


    HRESULT STDMETHODCALLTYPE CheckFeatureSupport(
        D3D12_FEATURE Feature,
        _Inout_updates_bytes_(FeatureSupportDataSize)  void* pFeatureSupportData,
        UINT FeatureSupportDataSize) override;



    void STDMETHODCALLTYPE CreateConstantBufferView(
        _In_opt_  const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
        _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

    void STDMETHODCALLTYPE CreateShaderResourceView(
        _In_opt_  ID3D12Resource* pResource,
        _In_opt_  const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
        _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

    void STDMETHODCALLTYPE CreateUnorderedAccessView(
        _In_opt_  ID3D12Resource* pResource,
        _In_opt_  ID3D12Resource* pCounterResource,
        _In_opt_  const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
        _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;


    void STDMETHODCALLTYPE CreateDepthStencilView(
        _In_opt_  ID3D12Resource* pResource,
        _In_opt_  const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
        _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

    void STDMETHODCALLTYPE CreateSampler(
        _In_  const D3D12_SAMPLER_DESC* pDesc,
        _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

    void STDMETHODCALLTYPE CopyDescriptors(
        _In_  UINT NumDestDescriptorRanges,
        _In_reads_(NumDestDescriptorRanges)  const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
        _In_reads_opt_(NumDestDescriptorRanges)  const UINT* pDestDescriptorRangeSizes,
        _In_  UINT NumSrcDescriptorRanges,
        _In_reads_(NumSrcDescriptorRanges)  const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
        _In_reads_opt_(NumSrcDescriptorRanges)  const UINT* pSrcDescriptorRangeSizes,
        _In_  D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType) override;

    void STDMETHODCALLTYPE CopyDescriptorsSimple(
        _In_  UINT NumDescriptors,
        _In_  D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
        _In_  D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
        _In_  D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType) override;

    D3D12_HEAP_PROPERTIES STDMETHODCALLTYPE GetCustomHeapProperties(
        _In_  UINT nodeMask,
        D3D12_HEAP_TYPE heapType) override;


    HRESULT STDMETHODCALLTYPE CreateHeap(
        _In_  const D3D12_HEAP_DESC* pDesc,
        REFIID riid,
        _COM_Outptr_opt_  void** ppvHeap) override;

    HRESULT STDMETHODCALLTYPE CreatePlacedResource(
        _In_  ID3D12Heap* pHeap,
        UINT64 HeapOffset,
        _In_  const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        _In_opt_  const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riid,
        _COM_Outptr_opt_  void** ppvResource) override;

    HRESULT STDMETHODCALLTYPE CreateReservedResource(
        _In_  const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        _In_opt_  const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riid,
        _COM_Outptr_opt_  void** ppvResource) override;

    HRESULT STDMETHODCALLTYPE CreateSharedHandle(
        _In_  ID3D12DeviceChild* pObject,
        _In_opt_  const SECURITY_ATTRIBUTES* pAttributes,
        DWORD Access,
        _In_opt_  LPCWSTR Name,
        _Out_  HANDLE* pHandle) override;

    HRESULT STDMETHODCALLTYPE OpenSharedHandle(
        _In_  HANDLE NTHandle,
        REFIID riid,
        _COM_Outptr_opt_  void** ppvObj) override;

    HRESULT STDMETHODCALLTYPE OpenSharedHandleByName(
        _In_  LPCWSTR Name,
        DWORD Access,
        /* [annotation][out] */
        _Out_  HANDLE* pNTHandle) override;

    HRESULT STDMETHODCALLTYPE MakeResident(
        UINT NumObjects,
        _In_reads_(NumObjects)  ID3D12Pageable* const* ppObjects) override;

    HRESULT STDMETHODCALLTYPE Evict(
        UINT NumObjects,
        _In_reads_(NumObjects)  ID3D12Pageable* const* ppObjects) override;


    HRESULT STDMETHODCALLTYPE GetDeviceRemovedReason(void) override;

    void STDMETHODCALLTYPE GetCopyableFootprints(
        _In_  const D3D12_RESOURCE_DESC* pResourceDesc,
        _In_range_(0, D3D12_REQ_SUBRESOURCES)  UINT FirstSubresource,
        _In_range_(0, D3D12_REQ_SUBRESOURCES - FirstSubresource)  UINT NumSubresources,
        UINT64 BaseOffset,
        _Out_writes_opt_(NumSubresources)  D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
        _Out_writes_opt_(NumSubresources)  UINT* pNumRows,
        _Out_writes_opt_(NumSubresources)  UINT64* pRowSizeInBytes,
        _Out_opt_  UINT64* pTotalBytes) override;

    HRESULT STDMETHODCALLTYPE CreateQueryHeap(
        _In_  const D3D12_QUERY_HEAP_DESC* pDesc,
        REFIID riid,
        _COM_Outptr_opt_  void** ppvHeap) override;

    HRESULT STDMETHODCALLTYPE SetStablePowerState(
        BOOL Enable) override;

    HRESULT STDMETHODCALLTYPE CreateCommandSignature(
        _In_  const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
        _In_opt_  ID3D12RootSignature* pRootSignature,
        REFIID riid,
        _COM_Outptr_opt_  void** ppvCommandSignature) override;

    void STDMETHODCALLTYPE GetResourceTiling(
        _In_  ID3D12Resource* pTiledResource,
        _Out_opt_  UINT* pNumTilesForEntireResource,
        _Out_opt_  D3D12_PACKED_MIP_INFO* pPackedMipDesc,
        _Out_opt_  D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
        _Inout_opt_  UINT* pNumSubresourceTilings,
        _In_  UINT FirstSubresourceTilingToGet,
        _Out_writes_(*pNumSubresourceTilings)  D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips) override;

    LUID STDMETHODCALLTYPE GetAdapterLuid(void) override;
    // ----method from ID3D12Object

    HRESULT STDMETHODCALLTYPE GetPrivateData(
        _In_  REFGUID guid,
        _Inout_  UINT* pDataSize,
        _Out_writes_bytes_opt_(*pDataSize)  void* pData);

    HRESULT STDMETHODCALLTYPE SetPrivateData(
        _In_  REFGUID guid,
        _In_  UINT DataSize,
        _In_reads_bytes_opt_(DataSize)  const void* pData);

    HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        _In_  REFGUID guid,
        _In_opt_  const IUnknown* pData);

    HRESULT STDMETHODCALLTYPE SetName(
        _In_z_  LPCWSTR Name);

    // ----method from IUnkown
    HRESULT STDMETHODCALLTYPE QueryInterface(
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject);

    ULONG STDMETHODCALLTYPE AddRef(void);

    ULONG STDMETHODCALLTYPE Release(void);
};

