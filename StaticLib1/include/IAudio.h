#ifndef THOMAS_IAUDIO_H
#define THOMAS_IAUDIO_H

#include <IService.h>
#include <string>

namespace thomas
{
	class IAudio : public IService
	{
	public:
		virtual ~IAudio() = default;
		//creer une map dans les services meme pour le id
		virtual int LoadMusic(const std::string& aFilename) = 0;
		virtual int LoadSound(const std::string& aFilename) = 0;

		virtual void PlayMusic(int aMusic, int aLoop) = 0;
		virtual void PlaySFX(int aSound, int aLoop) = 0;
		virtual void PauseMusic(int aMusic) = 0;
		virtual void StopMusic(int aMusic) = 0;
		virtual void ResumeMusic(int aMusic) = 0;

	};
}

#endif