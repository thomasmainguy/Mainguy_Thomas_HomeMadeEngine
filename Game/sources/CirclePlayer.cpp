#include "..\includes\CirclePlayer.h"
#include <Engine.h>
#include <EKeys.h>
#include <HashKey.h>

void thomas::CirclePlayer::Update(float aDeltaTime)
{
	GetInput().PoolEvents();
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_S))
	{
		m_Transform.Translate(0, 1 * m_Speed * aDeltaTime);
		m_Collider.Set(m_Transform.X + m_Transform.Height, m_Transform.Y + m_Transform.Height / 2, m_Transform.Height / 2);
	}
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_A))
	{
		m_Transform.Translate(-1 * m_Speed * aDeltaTime, 0);
		m_Collider.Set(m_Transform.X + m_Transform.Height, m_Transform.Y + m_Transform.Height, m_Transform.Height / 2);
	}
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_D))
	{
		m_Transform.Translate(1 * m_Speed * aDeltaTime, 0);
		m_Collider.Set(m_Transform.X + m_Transform.Height, m_Transform.Y + m_Transform.Height / 2, m_Transform.Height / 2);
	}
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_W))
	{
		m_Transform.Translate(0, -1 * m_Speed * aDeltaTime);
		m_Collider.Set(m_Transform.X + m_Transform.Height, m_Transform.Y + m_Transform.Height / 2, m_Transform.Height / 2);
	}
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_ESCAPE))
	{
		thomas::Engine::Instance().Stop();
	}
	m_Sprite.Update(&m_Transform, aDeltaTime);
	m_Collider.Set(m_Transform.X + m_Transform.Height, m_Transform.Y + m_Transform.Height / 2, m_Transform.Height / 2);

}

void thomas::CirclePlayer::Draw()
{
	if (GetCollider().IsColliding(m_Collider, m_Collision->GetEntityCollider()))
	{
		GetGraphic().SetColor(255, 0, 0, 255);
		GetGraphic().Draw(m_Collider);
	}
	else
	{
		GetGraphic().SetColor(0, 255, 0, 255);
		GetGraphic().Draw(m_Collider);
	}
	m_Sprite.Draw(GetGraphic());
}

void thomas::CirclePlayer::Start()
{

	m_Collision = (Collision*)GetScene().FindEntity("Collision");


	m_Transform.SetPosition(150, 150);
	m_Transform.SetHeight(100);
	m_Transform.SetWidth(100);

	m_Collider.Set(m_Transform.X, m_Transform.Y, 100);
}


void thomas::CirclePlayer::Destroy()
{
	delete this;
}
