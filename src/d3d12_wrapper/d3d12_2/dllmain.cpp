
//#pragma comment(lib, "d3d12.lib") 
#include "pch.h"
//#include <stdio.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Í·ÎÄ¼þ
#include <Windows.h>
#include <d3d12.h>
#include "ID3D12Device_Wrapper.h"
#include <wrl.h>
#include <stdio.h>
#include "Func_Wrapper.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// µ¼³öº¯Êý

#pragma comment(linker, "/EXPORT:GetBehaviorValue=d3d12_real.GetBehaviorValue,@100")
#pragma comment(linker, "/EXPORT:SetAppCompatStringPointer=d3d12_real.SetAppCompatStringPointer,@103")
#pragma comment(linker, "/EXPORT:D3D12CoreCreateLayeredDevice=d3d12_real.D3D12CoreCreateLayeredDevice,@104")
#pragma comment(linker, "/EXPORT:D3D12CoreGetLayeredDeviceSize=d3d12_real.D3D12CoreGetLayeredDeviceSize,@105")
#pragma comment(linker, "/EXPORT:D3D12CoreRegisterLayers=d3d12_real.D3D12CoreRegisterLayers,@106")
#pragma comment(linker, "/EXPORT:D3D12DeviceRemovedExtendedData=d3d12_real.D3D12DeviceRemovedExtendedData,@109")
#pragma comment(linker, "/EXPORT:D3D12GetInterface=d3d12_real.D3D12GetInterface,@111")
#pragma comment(linker, "/EXPORT:D3D12PIXEventsReplaceBlock=d3d12_real.D3D12PIXEventsReplaceBlock,@112")
#pragma comment(linker, "/EXPORT:D3D12PIXGetThreadInfo=d3d12_real.D3D12PIXGetThreadInfo,@113")
#pragma comment(linker, "/EXPORT:D3D12PIXNotifyWakeFromFenceSignal=d3d12_real.D3D12PIXNotifyWakeFromFenceSignal,@114")
#pragma comment(linker, "/EXPORT:D3D12PIXReportCounter=d3d12_real.D3D12PIXReportCounter,@115")


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AheadLib ÃüÃû¿Õ¼ä
namespace AheadLib
{
	HMODULE m_hModule = NULL;	// Ô­Ê¼Ä£¿é¾ä±ú
	DWORD m_dwReturn[19] = { 0 };	// Ô­Ê¼º¯Êý·µ»ØµØÖ·


	// ¼ÓÔØÔ­Ê¼Ä£¿é
	inline BOOL WINAPI Load()
	{
		m_hModule = LoadLibraryA("d3d12_real.dll");
		
		if (m_hModule == NULL)
		{
			MessageBox(NULL, TEXT("can not load d3d12_real library!"), TEXT("Darn"), 0);
		}

		return (m_hModule != NULL);
	}

	// ÊÍ·ÅÔ­Ê¼Ä£¿é
	inline VOID WINAPI Free()
	{
		if (m_hModule)
		{
			FreeLibrary(m_hModule);
		}
	}
}
using namespace AheadLib;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Èë¿Úº¯Êý
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	MessageBox(NULL, TEXT("this is fake d3d12!"), TEXT("Darn"), 0);
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		
		BOOL res = Load();
		return res;
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		Free();
	}

	
	return TRUE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



