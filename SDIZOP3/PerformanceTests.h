#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>

class PerformanceTests
{
	static double PCFreq;
	static __int64 CounterStart;

public:
	static void StartCounter() {
		LARGE_INTEGER li;
		if (!QueryPerformanceFrequency(&li))
			printf("QueryPerformanceFrequency failed!\n");

		PCFreq = double(li.QuadPart) / 1000.0;

		QueryPerformanceCounter(&li);
		CounterStart = li.QuadPart;
	}

	static double GetCounter() {
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		return double(li.QuadPart - CounterStart) / PCFreq;
	}

	static void makeBackpackTests();
	static void makeTspTests();
	PerformanceTests();
	~PerformanceTests();
};

