#include "..\includes\MainScene.h"
#include <Engine.h>
#include <BackGround.h>
#include <Title.h>


void thomas::MainScene::Load()
{
	thomas::Engine::Instance().GetScene().AddEntity("BackGround", new thomas::BackGround());
	thomas::Engine::Instance().GetScene().AddEntity("Title", new thomas::Title());
}
