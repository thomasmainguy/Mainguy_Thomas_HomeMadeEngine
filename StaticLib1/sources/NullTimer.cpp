#include "..\include\NullTimer.h"

bool thomas::NullTimer::Initialize()
{
	return true;
}

void thomas::NullTimer::Clean()
{
}

float thomas::NullTimer::GetTime()
{
	//return le current time
	return 0.0f;
}

void thomas::NullTimer::Wait(float aDelay)
{
	//return the time to sleep
}
