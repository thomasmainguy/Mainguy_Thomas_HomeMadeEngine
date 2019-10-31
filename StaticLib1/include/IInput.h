#ifndef THOMAS_IINPUT_H
#define THOMAS_IINPUT_H

#include <EKeys.h>
#include <IService.h>

namespace thomas
{
	class IInput :  public IService
	{
	public:
		virtual ~IInput() = default;

		virtual void PoolEvents() = 0;
		virtual bool IsKeyDown(EKeys aKey) = 0;
	};
}
#endif