// SetUnhandledExceptionFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <Errhandlingapi.h>


LONG WINAPI MyUnhandledExceptionFilter(_EXCEPTION_POINTERS *ExceptionInfo)
{
	ExceptionInfo->ContextRecord->Eip = ExceptionInfo->ContextRecord->Eip + 1;
	return EXCEPTION_CONTINUE_EXECUTION;
}


int main()
{
	::SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);

	char* ptr = 0;
	*ptr = 7;

	std::cout << "Good Job! No debugger is here..." << std::endl;

	getchar();
	return 0;
}

