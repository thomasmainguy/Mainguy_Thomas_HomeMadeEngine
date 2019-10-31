#include "NullInput.h"

bool thomas::NullInput::Initialize()
{
	return true;
}

void thomas::NullInput::Clean()
{
}

void thomas::NullInput::PoolEvents()
{
}

bool thomas::NullInput::IsKeyDown(EKeys aKey)
{
	return false;
}