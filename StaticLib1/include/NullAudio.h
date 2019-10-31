#ifndef THOMAS_NULLAUDIO_H
#define THOMAS_NULLAUDIO_H

#include <IAudio.h>
#include <string>
namespace thomas
{
	class NullAudio final : public IAudio
	{
	public:
		virtual ~NullAudio() = default;
		virtual bool Initialize() override;
		virtual void Clean() override;
		virtual int LoadMusic(const std::string& aFilename) override;
		virtual int LoadSound(const std::string& aFilename) override;
		virtual void PlayMusic(int aMusic, int aLoop) override;
		virtual void PlaySFX(int aSound, int aLoop) override;
		virtual void PauseMusic(int aMusic) override;
		virtual void StopMusic(int aMusic) override;
		virtual void ResumeMusic(int aMusic) override;
	};
}
#endif
