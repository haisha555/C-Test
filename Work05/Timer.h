#include <windows.h>

double stopwatch()
{
	unsigned long long ticks;
	unsigned long long ticks_per_sec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticks_per_sec);
	QueryPerformanceCounter((LARGE_INTEGER*)&ticks);
	return ((float)ticks) / (float)ticks_per_sec;
}
