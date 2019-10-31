#include "..\includes\Title.h"
#include <Engine.h>

class SDL_Texture;

void thomas::Title::Update(float aDeltaTime)
{
	GetInput().PoolEvents();

	if (GetInput().IsKeyDown(thomas::EKeys::KEY_F))
	{
		GetScene().Load("Gameplay");
	}
}

void thomas::Title::Draw()
{
	GetGraphic().Draw(m_FontId, m_Instructions, 400, 25);
}

void thomas::Title::Start()
{
	m_FontId = GetGraphic().LoadFont("Arial.ttf");
}

void thomas::Title::Destroy()
{
	delete this;
}
