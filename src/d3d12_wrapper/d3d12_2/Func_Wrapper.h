#pragma once

#include <d3d12.h>

FARPROC GetProcAddressFromRealD3D12(char* func);

// --- define function pointer from d3d12
typedef HRESULT(__stdcall* fn_D3D12CreateDevice) (IUnknown* pAdapter,
	D3D_FEATURE_LEVEL MinimumFeatureLevel,
	REFIID            riid,
	void** ppDevice);

typedef HRESULT(__stdcall* fn_D3D12GetDebugInterface) (_In_ REFIID riid, _COM_Outptr_opt_ void** ppvDebug);

typedef HRESULT(__stdcall* fn_D3D12CreateRootSignatureDeserializer)(
    _In_reads_bytes_(SrcDataSizeInBytes) LPCVOID pSrcData,
    _In_ SIZE_T SrcDataSizeInBytes,
    _In_ REFIID pRootSignatureDeserializerInterface,
    _Out_ void** ppRootSignatureDeserializer);

typedef HRESULT(__stdcall* fn_D3D12CreateVersionedRootSignatureDeserializer)(
    _In_reads_bytes_(SrcDataSizeInBytes) LPCVOID pSrcData,
    _In_ SIZE_T SrcDataSizeInBytes,
    _In_ REFIID pRootSignatureDeserializerInterface,
    _Out_ void** ppRootSignatureDeserializer);

typedef HRESULT(__stdcall* fn_D3D12EnableExperimentalFeatures)(
    UINT                                    NumFeatures,
    _In_count_(NumFeatures) const IID* pIIDs,
    _In_opt_count_(NumFeatures) void* pConfigurationStructs,
    _In_opt_count_(NumFeatures) UINT* pConfigurationStructSizes);

typedef HRESULT(__stdcall* fn_D3D12SerializeRootSignature)(
    _In_ const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
    _In_ D3D_ROOT_SIGNATURE_VERSION Version,
    _Out_ ID3DBlob** ppBlob,
    _Always_(_Outptr_opt_result_maybenull_) ID3DBlob** ppErrorBlob);

typedef HRESULT(__stdcall* fn_D3D12SerializeVersionedRootSignature)(
    _In_ const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
    _Out_ ID3DBlob** ppBlob,
    _Always_(_Outptr_opt_result_maybenull_) ID3DBlob** ppErrorBlob);