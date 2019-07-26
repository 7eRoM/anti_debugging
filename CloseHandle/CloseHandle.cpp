// CloseHandle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>

int main()
{
	CloseHandle((HANDLE)0x12345678); // Under debugging: STATUS_INVALID_HANDLE (0xC0000008) 
	
	std::cout << "No Crash, No Debugger!" << std::endl;

	getchar();
	return 0;
}

