#include <d3d12.h>
#include <wrl.h>
#include <Windows.h>
#include <d3d12.h>

#include "pch.h"
#include "Func_Wrapper.h"
#include "ID3D12Device_Wrapper.h"


typedef HRESULT(__stdcall* fn_D3D12CreateDevice) (IUnknown* pAdapter,
	D3D_FEATURE_LEVEL MinimumFeatureLevel,
	REFIID            riid,
	void** ppDevice);


FARPROC GetProcAddressFromRealD3D12(char* func)
{
	HMODULE d3d_dll = LoadLibraryA("d3d12_real.dll");

	if (!d3d_dll)
	{
		MessageBox(NULL, TEXT("Could Not Locate Original D3D12 DLL"), TEXT("Darn"), 0);
		return nullptr;
	}

	return GetProcAddress(d3d_dll, func);
}

extern "C" HRESULT WINAPI D3D12CreateDevice_Wrapper(_In_opt_ IUnknown * pAdapter,
	D3D_FEATURE_LEVEL MinimumFeatureLevel,
	_In_ REFIID riid, // Expected: ID3D12Device
	_COM_Outptr_opt_ void** ppDevice)
{
//	MessageBox(NULL, TEXT("this is fake d3d12create Device!"), TEXT("Darn"), 0);
	char funcName[50] = "D3D12CreateDevice";
	fn_D3D12CreateDevice D3D12CreateDevice_Orig = (fn_D3D12CreateDevice)GetProcAddressFromRealD3D12(funcName);
	
	HRESULT res = D3D12CreateDevice_Orig(pAdapter, MinimumFeatureLevel, riid, ppDevice);
	Microsoft::WRL::ComPtr <ID3D12Device_Wrapper> wrapped_device;

	if (ppDevice == NULL)
	{
		return res;
	}

	Microsoft::WRL::ComPtr <ID3D12Device_Wrapper> wrapper_addr;

	ID3D12Device_Wrapper* wrapper_object = new ID3D12Device_Wrapper(reinterpret_cast<ID3D12Device*>(*ppDevice));

	*ppDevice = reinterpret_cast<void*>(wrapper_object);

	if (ppDevice == NULL)
	{
		MessageBox(NULL, TEXT("ppDevice is null; somethingWrong!"), TEXT("Darn"), 0);
	}

	return res;
}

extern "C" HRESULT WINAPI D3D12GetDebugInterface_Wrapper(_In_ REFIID riid, _COM_Outptr_opt_ void** ppvDebug)
{
	char funcName[50] = "D3D12GetDebugInterface";
	fn_D3D12GetDebugInterface D3D12GetDebugInterface_Orig = (fn_D3D12GetDebugInterface)GetProcAddressFromRealD3D12(funcName);
	return D3D12GetDebugInterface_Orig(riid, ppvDebug);
}

extern "C" HRESULT WINAPI D3D12CreateRootSignatureDeserializer_Wrapper(
	_In_reads_bytes_(SrcDataSizeInBytes) LPCVOID pSrcData,
	_In_ SIZE_T SrcDataSizeInBytes,
	_In_ REFIID pRootSignatureDeserializerInterface,
	_Out_ void** ppRootSignatureDeserializer)
{
	char funcName[50] = "D3D12CreateRootSignatureDeserializer";
	fn_D3D12CreateRootSignatureDeserializer D3D12CreateRootSignatureDeserializer_Orig = (fn_D3D12CreateRootSignatureDeserializer)GetProcAddressFromRealD3D12(funcName);
	return D3D12CreateRootSignatureDeserializer_Orig(pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
}

extern "C" HRESULT WINAPI D3D12CreateVersionedRootSignatureDeserializer_Wrapper(
	_In_reads_bytes_(SrcDataSizeInBytes) LPCVOID pSrcData,
	_In_ SIZE_T SrcDataSizeInBytes,
	_In_ REFIID pRootSignatureDeserializerInterface,
	_Out_ void** ppRootSignatureDeserializer)
{
	char funcName[50] = "D3D12CreateVersionedRootSignatureDeserializer";
	fn_D3D12CreateVersionedRootSignatureDeserializer D3D12CreateVersionedRootSignatureDeserializer_Orig = (fn_D3D12CreateVersionedRootSignatureDeserializer)GetProcAddressFromRealD3D12(funcName);
	return D3D12CreateVersionedRootSignatureDeserializer_Orig(pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
}

extern "C" HRESULT WINAPI D3D12EnableExperimentalFeatures_Wrapper(
	UINT                                    NumFeatures,
	_In_count_(NumFeatures) const IID * pIIDs,
	_In_opt_count_(NumFeatures) void* pConfigurationStructs,
	_In_opt_count_(NumFeatures) UINT * pConfigurationStructSizes)
{
	char funcName[50] = "D3D12EnableExperimentalFeatures";
	fn_D3D12EnableExperimentalFeatures D3D12EnableExperimentalFeatures_Orig = (fn_D3D12EnableExperimentalFeatures)GetProcAddressFromRealD3D12(funcName);
	return D3D12EnableExperimentalFeatures_Orig(NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes);
}

extern "C" HRESULT WINAPI D3D12SerializeRootSignature_Wrapper(
	_In_ const D3D12_ROOT_SIGNATURE_DESC * pRootSignature,
	_In_ D3D_ROOT_SIGNATURE_VERSION Version,
	_Out_ ID3DBlob * *ppBlob,
	_Always_(_Outptr_opt_result_maybenull_) ID3DBlob * *ppErrorBlob)
{
	char funcName[50] = "D3D12SerializeRootSignature";
	fn_D3D12SerializeRootSignature D3D12SerializeRootSignature_Orig = (fn_D3D12SerializeRootSignature)GetProcAddressFromRealD3D12(funcName);
	return D3D12SerializeRootSignature_Orig(pRootSignature, Version, ppBlob, ppErrorBlob);
}

extern "C" HRESULT WINAPI D3D12SerializeVersionedRootSignature_Wrapper(
	_In_ const D3D12_VERSIONED_ROOT_SIGNATURE_DESC * pRootSignature,
	_Out_ ID3DBlob * *ppBlob,
	_Always_(_Outptr_opt_result_maybenull_) ID3DBlob * *ppErrorBlob)
{
	char funcName[50] = "D3D12SerializeVersionedRootSignature";
	fn_D3D12SerializeVersionedRootSignature D3D12SerializeVersionedRootSignature_Orig = (fn_D3D12SerializeVersionedRootSignature)GetProcAddressFromRealD3D12(funcName);
	return D3D12SerializeVersionedRootSignature_Orig(pRootSignature, ppBlob, ppErrorBlob);
}
