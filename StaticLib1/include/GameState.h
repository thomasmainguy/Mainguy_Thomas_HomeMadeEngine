#ifndef THOMAS_GAMESTATE_H
#define THOMAS_GAMESTATE_H

namespace thomas
{
	class GameState
	{
	public:
		virtual ~GameState() = default;

		virtual void Load() = 0;
	};
}
#endif