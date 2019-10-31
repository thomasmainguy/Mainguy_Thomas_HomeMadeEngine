#ifndef THOMAS_AUDIO_H
#define THOMAS_AUDIO_H

#include <IAudio.h>
#include <string>
#include <map>
#include <stdio.h>
#include <SDL_mixer.h>

namespace thomas
{
	class Audio final : public IAudio
	{
	public:
		virtual ~Audio() = default;
		virtual bool Initialize() override;
		virtual void Clean() override;
		//creer une map dans les services meme pour le id
		virtual int LoadMusic(const std::string& aFilename) override;
		virtual int LoadSound(const std::string& aFilename) override;

		virtual void PlayMusic(int aMusic, int aLoop) override;
		virtual void PlaySFX(int aSound, int aLoop) override;
		virtual void PauseMusic(int aMusic) override;
		virtual void StopMusic(int aMusic) override;
		virtual void ResumeMusic(int aMusic) override;
	private:
		typedef std::map<unsigned int, Mix_Chunk*> TChunkMap;
		typedef std::map<unsigned int, _Mix_Music*> TMusicMap;

		TChunkMap m_SoundCache;
		TMusicMap m_MusicCache;
	};
}

#endif
