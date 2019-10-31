#include "..\includes\TuileEau.h"
#include <Engine.h>

void thomas::TuileEau::Update(float aDeltaTime)
{
	m_SpriteSheet.Update(&m_Transform, aDeltaTime);
}

void thomas::TuileEau::Draw()
{
	m_Transform.SetPosition(0, 0);
	m_SpriteSheet.SetFrame("TuileTerre");
	m_SpriteSheet.Draw(GetGraphic());
	m_SpriteSheet.Update(&m_Transform, 0);

	m_Transform.SetPosition(32, 0);
	m_SpriteSheet.SetFrame("TuileEau");
	m_SpriteSheet.Draw(GetGraphic());
	m_SpriteSheet.Update(&m_Transform, 0);

	m_Transform.SetPosition(64, 0);
	m_SpriteSheet.SetFrame("PieceOr");
	m_SpriteSheet.Draw(GetGraphic());
	m_SpriteSheet.Update(&m_Transform, 0);
}

void thomas::TuileEau::Start()
{
	std::string tString = "env.png";
	m_SpriteSheet.Load(GetGraphic(), tString);

	m_SpriteSheet.AddFrame("TuileEau", 0, 0, 32, 32);
	m_SpriteSheet.AddFrame("TuileTerre", 256, 160, 32, 32);
	m_SpriteSheet.AddFrame("PieceOr", 352, 192, 32, 32);

	m_Transform.SetPosition(0, 0);
	m_Transform.SetHeight(32);
	m_Transform.SetWidth(32);
}

void thomas::TuileEau::Destroy()
{
	delete this;
}
