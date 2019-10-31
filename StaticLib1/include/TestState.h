#ifndef THOMAS_TESTSTATE_H
#define THOMAS_TESTSTATE_H

#include <GameState.h>

namespace thomas
{
	class TestState : public thomas::GameState
	{
	public:
		virtual ~TestState() = default;
		void Load() override;

	};
}
#endif
