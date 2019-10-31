#include <FirstScene.h>
#include <Engine.h>
#include <FirstPlayer.h>
#include <BackGround.h>
#include <vector>
#include <TitleGamplay.h>
#include <TuileEau.h>

void thomas::FirstScene::Load()
{
	thomas::Engine::Instance().GetScene().AddEntity("BackGround", new thomas::BackGround());
	thomas::Engine::Instance().GetScene().AddEntity("Player", new thomas::FirstPlayer());
	thomas::Engine::Instance().GetScene().AddEntity("TitleGameplay", new thomas::TitleGamplay());
	thomas::Engine::Instance().GetScene().AddEntity("Tuile Eau", new thomas::TuileEau());
}
