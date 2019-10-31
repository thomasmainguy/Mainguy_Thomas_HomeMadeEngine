#include "..\includes\RectangleCollision.h"
#include <Collision.h>
#include <Engine.h>

void thomas::RectangleCollision::Update(float aDeltaTime)
{
	if (GetCollider().IsColliding(m_Collider, m_Collision->GetEntityCollider()))
	{
		m_Transform.SetPosition(800, 0);
	}
	else
	{
		m_Transform.Translate(-1 * m_Speed * aDeltaTime, 0);
	}
	
	m_Collider.Set(m_Transform.X, m_Transform.Y, m_Transform.Width, m_Transform.Height);
	m_Sprite.Update(&m_Transform, aDeltaTime);
}

void thomas::RectangleCollision::Draw()
{	
	
	GetGraphic().Draw(m_Collider);
	m_Sprite.Draw(GetGraphic());
}

void thomas::RectangleCollision::Start()
{
	m_Collision = (Collision*)GetScene().FindEntity("Collision");

	std::string tString = "collision.png";
	int w, h;

	m_TextureId = GetGraphic().LoadTexture(tString);
	m_Transform.SetPosition(800, 0);
	GetGraphic().GetTextureSize(m_TextureId, &w, &h);
	m_Transform.SetHeight(h);
	m_Transform.SetWidth(w);

	GetGraphic().LoadTexture(tString);
	m_Sprite.Load(GetGraphic(), tString);

	m_Collider.Set(m_Transform.X, m_Transform.Y, m_Transform.Width, m_Transform.Height);
}

void thomas::RectangleCollision::Destroy()
{
	delete this;
}

