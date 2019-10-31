#include <BackGround.h>
#include <Engine.h>
#include <string>
#include <HashKey.h>

void thomas::BackGround::Update(float aDeltaTime)
{
}

void thomas::BackGround::Draw()
{
	thomas::Rectangle tRectSrc;
	tRectSrc.Set(0, 0, 900, 900);

	thomas::Rectangle tRectDst;
	tRectDst.Set(0, 0, 900, 900);

	thomas::Engine::Instance().GetGraphic().Draw(m_BackGroundId, tRectSrc ,tRectDst ,0 ,true , 255);
}

void thomas::BackGround::Start()
{
	m_MusicId = thomas::Engine::Instance().GetAudio().LoadMusic("Music.mp3");
	
	if (m_MusicId != -1)
	{
		thomas::Engine::Instance().GetAudio().PlayMusic(m_MusicId, 100000);
	}

	m_BackGroundId = thomas::Engine::Instance().GetGraphic().LoadTexture("Background.jpg");

}

void thomas::BackGround::Destroy()
{

}
