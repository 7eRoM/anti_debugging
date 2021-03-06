// PEB_IsDebugged.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>

int main()
{
	bool is_debugger_present = false;

	__asm
	{
		push eax
		mov eax, fs:[30h]
		mov al, byte ptr[eax + 2]
		test al, al
		je NoDebugger
		mov checked, 1
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
