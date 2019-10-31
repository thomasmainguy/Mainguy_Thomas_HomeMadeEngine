#ifndef THOMAS_FIRSTSCENE_H
#define THOMAS_FIRSTSCENE_H

#include <Entity.h>
#include <GameState.h>


namespace thomas
{
	class FirstScene : public thomas::GameState
	{
	public:
		virtual ~FirstScene() = default;
		void Load() override;
	};
}
#endif