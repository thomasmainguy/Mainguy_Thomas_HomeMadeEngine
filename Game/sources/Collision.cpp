#include "Collision.h"
#include <Engine.h>

void thomas::Collision::Update(float aDeltaTime)
{
	m_Sprite.Update(&m_Transform, aDeltaTime);
}

void thomas::Collision::Draw()
{
	GetGraphic().Draw(m_Collider);
	m_Sprite.Draw(GetGraphic());
}

void thomas::Collision::Start()
{
	std::string tString = "collision.png";
	int w, h;

	m_TextureId = GetGraphic().LoadTexture(tString);
	m_Transform.SetPosition(150, 45);
	GetGraphic().GetTextureSize(m_TextureId, &w, &h);
	m_Transform.SetHeight(h);
	m_Transform.SetWidth(w);

	GetGraphic().LoadTexture(tString);
	m_Sprite.Load(GetGraphic(), tString);

	m_Collider.Set(m_Transform.X, m_Transform.Y, m_Transform.Width, m_Transform.Height);
}

void thomas::Collision::Destroy()
{
	delete this;
}
