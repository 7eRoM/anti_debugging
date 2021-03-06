// NtQueryInformationProcess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <winternl.h>
#include <ntstatus.h>

typedef NTSTATUS(NTAPI *pNtQueryInformationProcess)(
	IN  HANDLE ProcessHandle,
	IN  PROCESSINFOCLASS ProcessInformationClass,
	OUT PVOID ProcessInformation,
	IN  ULONG ProcessInformationLength,
	OUT PULONG ReturnLength    OPTIONAL
	);


int main()
{
	HMODULE hNtDll = LoadLibrary(L"ntdll.dll");
	if (hNtDll == NULL)
	{
		std::cout << "Unable to load ntdll!" << std::endl;
		getchar();
		return 1;
	}

	pNtQueryInformationProcess NtQueryInformationProcess = (pNtQueryInformationProcess)GetProcAddress(hNtDll, "NtQueryInformationProcess");
	if (NtQueryInformationProcess == NULL)
	{
		std::cout << "Unable to GetProcAddress of NtQueryInformationProcess!" << std::endl;
		FreeLibrary(hNtDll);
		getchar();
		return 1;
	}

	int is_debugger_present = 0;
	NTSTATUS status = NtQueryInformationProcess(GetCurrentProcess(), ProcessDebugPort, &is_debugger_present, sizeof(DWORD), NULL);
	if (!NT_SUCCESS(status))
	{
		std::cout << "Failed in NtQueryInformationProcess!" << std::endl;
		getchar();
		return 1;
	}

	if (is_debugger_present != 0)
		std::cout << "Hello Debugger!\n";
	else
		std::cout << "No Debugger!\n";

	FreeLibrary(hNtDll);

final_step:
	getchar();
	return 0;
}