#include <Engine.h>
#include <TitleGamplay.h>

class SDL_Texture;

void thomas::TitleGamplay::Update(float aDeltaTime)
{

}

void thomas::TitleGamplay::Draw()
{
	GetGraphic().Draw(m_FontId, m_Title, 390, 25);
}

void thomas::TitleGamplay::Start()
{
	m_FontId = GetGraphic().LoadFont("Arial.ttf");
	if (m_FontId != 0)
	{
		GetGraphic().GetFontSize(m_FontId, m_Title, &m_W, &m_H);
	}
}

void thomas::TitleGamplay::Destroy()
{
	delete this;
}