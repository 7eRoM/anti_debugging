// NtSetInformationThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <winternl.h>
#include <ntstatus.h>
#include <thread>


typedef NTSTATUS(NTAPI *pNtSetInformationThread)(
	IN HANDLE               ThreadHandle,
	IN int ThreadInformationClass,
	IN PVOID                ThreadInformation,
	IN ULONG                ThreadInformationLength
	);

int main()
{
	std::cout << "Hello..." << std::endl;

	HMODULE hNtDll = LoadLibrary(L"ntdll.dll");
	if (hNtDll == NULL)
	{
		std::cout << "Unable to load ntdll!" << std::endl;
		return 1;
	}

	pNtSetInformationThread NtSetInformationThread = (pNtSetInformationThread)GetProcAddress(hNtDll, "NtSetInformationThread");
	if (NtSetInformationThread == NULL)
	{
		std::cout << "Unable to GetProcAddress of NtSetInformationThread!" << std::endl;
		FreeLibrary(hNtDll);
		return 1;
	}

	NtSetInformationThread(GetCurrentThread(), 0x11, 0, 0);

	std::cout << "I`m hidden :)" << std::endl;

	FreeLibrary(hNtDll);

final_step:
	getchar();
	return 0;
}