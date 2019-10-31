#include "NullAudio.h"
#include "..\include\NullLog.h"

bool thomas::NullAudio::Initialize()
{
	return true;
}

void thomas::NullAudio::Clean()
{
}

int thomas::NullAudio::LoadMusic(const std::string & aFilename)
{
	return false;
}

int thomas::NullAudio::LoadSound(const std::string & aFilename)
{
	return false;
}

void thomas::NullAudio::PlayMusic(int aMusic, int aLoop)
{
}

void thomas::NullAudio::PlaySFX(int aSound, int aLoop)
{
}

void thomas::NullAudio::PauseMusic(int aMusic)
{
}

void thomas::NullAudio::StopMusic(int aMusic)
{
}

void thomas::NullAudio::ResumeMusic(int aMusic)
{
}

