#ifndef THOMAS_MAINSCENE_H
#define THOMAS_MAINSCENE_H

#include <Entity.h>
#include <GameState.h>


namespace thomas
{
	class MainScene : public thomas::GameState
	{
	public:
		virtual ~MainScene() = default;
		void Load() override;
	};
}
#endif
