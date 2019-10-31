#include <FirstPlayer.h>
#include <Engine.h>
#include <EKeys.h>
#include <HashKey.h>
#include <Animation.h>


void thomas::FirstPlayer::Update(float aDeltaTime)
{
	m_Animateur.Update(&m_Transform, aDeltaTime);
	GetInput().PoolEvents();
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_S))
	{
		m_Transform.Translate(0, 1 * m_Speed * aDeltaTime);
		m_Collider.Set(0, 1 * m_Speed * aDeltaTime,m_Transform.Width,m_Transform.Height);
	}
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_A))
	{
		m_Transform.SetFlip(true);
		m_Transform.Translate(-1 * m_Speed * aDeltaTime, 0 );
		m_Collider.Set(0, 1 * m_Speed * aDeltaTime, m_Transform.Width, m_Transform.Height);
	}
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_D))
	{
		m_Transform.SetFlip(false);
		m_Transform.Translate(1 * m_Speed * aDeltaTime, 0 );
		m_Collider.Set(0, 1 * m_Speed * aDeltaTime, m_Transform.Width, m_Transform.Height);
	}
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_W))
	{
		m_Transform.Translate(0, -1 * m_Speed * aDeltaTime);
		m_Collider.Set(0, 1 * m_Speed * aDeltaTime, m_Transform.Width, m_Transform.Height);
	}
	if (GetInput().IsKeyDown(thomas::EKeys::KEY_ESCAPE))
	{
		thomas::Engine::Instance().Stop();
	}
	m_Animateur.Update(&m_Transform, aDeltaTime);
	m_Collider.Set(m_Transform.X, m_Transform.Y, m_Transform.Width, m_Transform.Height);
}

void thomas::FirstPlayer::Draw()
{
	/*Collider
	if (GetCollider().IsColliding(m_Collider, m_Collision->GetEntityCollider()))
	{
		GetGraphic().SetColor(255, 0, 0, 255);
		GetGraphic().Draw(m_Collider);
	}
	else
	{
		GetGraphic().SetColor(0, 255, 0, 255);
		GetGraphic().Draw(m_Collider);
	}*/

	m_Animateur.Draw(GetGraphic());
}

void thomas::FirstPlayer::Start()
{
	std::string tString = "walk.png";
	m_Animateur.Load(GetGraphic(), tString);
	m_Animateur.InitAnimation(3, 32, 64);

	m_TextureId = GetGraphic().LoadTexture(tString);

	m_Transform.SetPosition(450, 450);
	m_Transform.SetHeight(64);
	m_Transform.SetWidth(32);

	GetGraphic().LoadTexture(tString);
	
	m_Animateur.Play(0, 3, 0.2, true);


	/*Collider 
	m_Collision = (Collision*)GetScene().FindEntity("Collision");
	m_Collider.Set(m_Transform.X, m_Transform.Y, m_Transform.Width, m_Transform.Height);*/
}

void thomas::FirstPlayer::Destroy()
{
	m_Animateur.Stop();
	delete this;
}
