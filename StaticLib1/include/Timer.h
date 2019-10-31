#ifndef THOMAS_TIMER_H
#define THOMAS_TIMER_H

#include <ITimer.h>

namespace thomas
{
	class Timer final : public ITimer

	{
	public:

		virtual ~Timer() = default;

		// Inherited via ITimer
		virtual bool Initialize() override;
		virtual void Clean() override;
		virtual float GetTime() override;
		virtual void Wait(float aDelay) override;

	};
}
#endif
