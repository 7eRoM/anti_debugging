// kernel32_IsDebuggerPresent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <debugapi.h>

int main()
{
	bool is_debugger_present = IsDebuggerPresent();
	if(is_debugger_present)
		std::cout << "Hello Debugger!\n"; 
	else
		std::cout << "No Debugger!\n";

	getchar();
	return 0;
}

