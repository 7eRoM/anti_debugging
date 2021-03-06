// QueryPerformanceCounter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>

#define THRESHOLD 10000     // Estmated elapsing time of executing the imporatant code in mili-seconds

double PCFreq = 0.0;
LONGLONG counter_start = 0;

void InitCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	counter_start = li.QuadPart;
}

double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - counter_start) / PCFreq;
}

int main()
{
	InitCounter();

	double start_time = GetCounter();

	std::cout << "Your important codes go here! (press any key to continue...)" << std::endl;
	getchar();

	double end_time = GetCounter();

	double elapsed_time = end_time - start_time;
	std::cout << "Elapsed time: " << elapsed_time << std::endl;

	if (elapsed_time > THRESHOLD)
		std::cout << "Hello Debugger!\n";
	else
		std::cout << "No Debugger!\n";

	getchar();
	return 0;
}

