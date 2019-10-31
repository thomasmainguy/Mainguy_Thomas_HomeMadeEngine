#include "..\include\Timer.h"
#include <SDL.h>
#ifdef _WIN32
	#include <Windows.h> // visual studio
#endif

bool thomas::Timer::Initialize()
{
	return true;
}

void thomas::Timer::Clean()
{
}

float thomas::Timer::GetTime()
{
	return GetCurrentTime();
}

void thomas::Timer::Wait(float aDelay)
{
	if (aDelay > 0)
	{
		Sleep(aDelay);
	}
}
