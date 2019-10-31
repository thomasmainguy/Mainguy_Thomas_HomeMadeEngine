#ifndef THOMAS_SDLINPUT_H
#define THOMAS_SDLINPUT_H

#include <IInput.h>

namespace thomas
{
	class SDLInput final : public IInput
	{
	public:
		virtual ~SDLInput() = default;

		virtual bool Initialize() override;
		virtual void Clean() override;
		virtual void PoolEvents() override;
		virtual bool IsKeyDown(EKeys aKey) override;
	private:

		const unsigned char* KeyBoardState;
	};
}
#endif