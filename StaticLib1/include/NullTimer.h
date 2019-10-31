#ifndef THOMAS_NULLTIMER_H
#define THOMAS_NULLTIMER_H

#include<ITimer.h>

namespace thomas
{
	class NullTimer final : public ITimer
	{
	public:
		virtual ~NullTimer() = default;

		bool Initialize() override;
		void Clean() override;
		float GetTime() override;
		void Wait(float aDelay) override;

	};
}
#endif

