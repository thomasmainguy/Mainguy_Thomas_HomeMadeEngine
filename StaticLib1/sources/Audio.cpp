#include "..\include\Audio.h"
#include <SDL_mixer.h>
#include <HashKey.h>
#include <Engine.h>

bool thomas::Audio::Initialize()
{
	return true;
}

void thomas::Audio::Clean()
{
}

int thomas::Audio::LoadMusic(const std::string & aFilename)
{
	const unsigned int tHashValue = thomas::HashKey::Generate(aFilename.c_str());

	if (m_MusicCache.count(tHashValue) > 0)
	{
		return tHashValue;
	}

	if (Mix_LoadMUS(aFilename.c_str()) != nullptr)
	{
		return tHashValue;
	}
	else
	{
		thomas::Engine::Instance().GetLog().LogUsingVS("the music your'e trying to load is empty ");
		return 0;
	}
	return 0;
}

int thomas::Audio::LoadSound(const std::string & aFilename)
{
	const unsigned int tHashValue = thomas::HashKey::Generate(aFilename.c_str());

	if (m_SoundCache.count(tHashValue) > 0)
	{
		return tHashValue;
	}

	if (Mix_LoadWAV(aFilename.c_str()) != nullptr && m_SoundCache.count(tHashValue) == 0)
	{
		return tHashValue;
	}
	else
	{
		thomas::Engine::Instance().GetLog().LogUsingVS("the sound your'e trying to load is empty ");
		return 0;
	}
	return 0;
}

void thomas::Audio::PlayMusic(int aMusic, int aLoop)
{
	//play from list id aMusic
	Mix_PlayMusic(m_MusicCache.find(aMusic)->second, aLoop);
}

void thomas::Audio::PlaySFX(int aSound, int aLoop)
{
	//play from list id aSound
	Mix_PlayChannel(-1, m_SoundCache.find(aSound)->second, aLoop);
}

void thomas::Audio::PauseMusic(int aMusic)
{
	Mix_PauseMusic();
}

void thomas::Audio::StopMusic(int aMusic)
{
	Mix_HaltMusic();
}

void thomas::Audio::ResumeMusic(int aMusic)
{
	//play from list id aMusic
	Mix_ResumeMusic();
}
