// PEB_NtGlobalFlags.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <debugapi.h>

int main()
{
	bool is_debugger_present = false;

	__asm
	{
		push eax
		mov eax, fs:[30h]
		mov al, byte ptr[eax + 68h]
		and al, 0x70
		test al, al
		je NoDebugger
		mov is_debugger_present, 1
	NoDebugger:
		pop eax
	}

	if (is_debugger_present)
		std::cout << "Hello Debugger!\n";
	else
		std::cout << "No Debugger!\n";

	getchar();
	return 0;
}