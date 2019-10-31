#include "..\includes\ColliderScene.h"
#include <Engine.h>
#include <CirclePlayer.h>
#include <BackGround.h>
#include <vector>
#include <TitleGamplay.h>
#include <Collision.h>
#include <TuileEau.h>
#include <RectangleCollision.h>

void thomas::ColliderScene::Load()
{
	thomas::Engine::Instance().GetScene().AddEntity("BackGround", new thomas::BackGround());
	thomas::Engine::Instance().GetScene().AddEntity("Player", new thomas::CirclePlayer());
	thomas::Engine::Instance().GetScene().AddEntity("Collision", new thomas::Collision());
	thomas::Engine::Instance().GetScene().AddEntity("RectCollision", new thomas::RectangleCollision());


}
