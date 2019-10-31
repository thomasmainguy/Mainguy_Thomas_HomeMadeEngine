#ifndef THOMAS_COLLIDERSCENE_H
#define THOMAS_COLLIDERSCENE_H

#include <Entity.h>
#include <GameState.h>


namespace thomas
{
	class ColliderScene : public thomas::GameState
	{
	public:
		virtual ~ColliderScene() = default;
		void Load() override;
	};
}
#endif