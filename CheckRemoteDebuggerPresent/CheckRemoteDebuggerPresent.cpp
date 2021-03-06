// CheckRemoteDebuggerPresent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <debugapi.h>
#include <processthreadsapi.h>

int main()
{
	BOOL is_debugger_present;
	if (CheckRemoteDebuggerPresent(GetCurrentProcess(), &is_debugger_present) == 0)
	{
		std::cout << "Failed in CheckRemoteDebuggerPresent: " << GetLastError() << std::endl;
		goto final_step;
	}
	else
	{
		if(is_debugger_present)
			std::cout << "Hello Debugger!\n";
		else
			std::cout << "No Debugger!\n";
	}

final_step:
	getchar();
	return 0;
}
