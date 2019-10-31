#include "..\include\Log.h"
#include <Windows.h>

bool thomas::Log::Initialize()
{
	return true;
}

void thomas::Log::Clean()
{
}

void thomas::Log::LogUsingVS(const std::string & aMessage)
{
	OutputDebugString(aMessage.c_str());
}
