#ifndef THOMAS_NULLINPUT_H
#define THOMAS_NULLINPUT_H

#include <IInput.h>

namespace thomas
{
	class NullInput final : public IInput
	{
	public:
		virtual ~NullInput() = default;

		virtual bool Initialize() override;
		virtual void Clean() override;
		virtual void PoolEvents() override;
		virtual bool IsKeyDown(EKeys aKey) override;
	};

}
#endif