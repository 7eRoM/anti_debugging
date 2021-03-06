// GetTickCount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>

#define THRESHOLD 10000     // Estmated elapsing time of executing the imporatant code in mili-seconds

int main()
{
	double start_time = GetTickCount();

	std::cout << "Your important codes go here! (press any key to continue...)" << std::endl;
	getchar();

	double end_time = GetTickCount();

	double elapsed_time = end_time - start_time;
	std::cout << "Elapsed time: " << elapsed_time << std::endl;

	if (elapsed_time > THRESHOLD)
		std::cout << "Hello Debugger!\n";
	else
		std::cout << "No Debugger!\n";

	getchar();
	return 0;
}
