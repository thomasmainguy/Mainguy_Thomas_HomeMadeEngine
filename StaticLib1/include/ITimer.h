#ifndef THOMAS_ITIMER_H
#define THOMAS_ITIMER_H

#include<IService.h>

namespace thomas
{
	class ITimer : public IService
	{
	public:
		virtual ~ITimer() = default;
		virtual float GetTime() = 0;
		virtual void Wait(float aDelay) = 0;
	};
}
#endif // !THOMAS_ITIMER_H

