#include <Engine.h>
#include <GameState.h>
#include <FirstScene.h>
#include <MainScene.h>
#include <ColliderScene.h>
#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <crtdbg.h>

int main()
{

	if (thomas::Engine::Instance().Initialize("TestGame", 1920, 1080))
	{
		thomas::Engine::Instance().GetScene().Register("Gameplay", new thomas::FirstScene());
		thomas::Engine::Instance().GetScene().Register("Menu", new thomas::MainScene());
		thomas::Engine::Instance().GetScene().Register("ColliderScene", new thomas::ColliderScene());
		thomas::Engine::Instance().GetScene().Load("Menu");
		thomas::Engine::Instance().Start();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}