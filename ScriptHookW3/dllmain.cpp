// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "main.h"

std::shared_ptr<shw3::Main> main;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		main.reset(new shw3::Main);
		main->initialize();
		break;
	case DLL_PROCESS_DETACH:
		main.reset();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

