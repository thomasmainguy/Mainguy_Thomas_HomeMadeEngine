#include "..\include\SDLInput.h"
#include <Engine.h>
#include <SDL.h>

bool thomas::SDLInput::Initialize()
{
	return true;
}

void thomas::SDLInput::Clean()
{
}

void thomas::SDLInput::PoolEvents()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			thomas::Engine::Instance().Stop();
			break;

		case SDL_KEYDOWN:
			KeyBoardState = SDL_GetKeyboardState(nullptr);
			break;

		case SDL_KEYUP:
			KeyBoardState = SDL_GetKeyboardState(nullptr);
			break;
		}
	}
}

bool thomas::SDLInput::IsKeyDown(EKeys aKey)
{
	if (KeyBoardState != nullptr)
	{
		if (KeyBoardState[aKey]) 
		{
			return true;
		}
	}
	return false;
	
}
