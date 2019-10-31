#include "..\include\SpriteSheet.h"

void thomas::SpriteSheet::AddFrame(const std::string & aName, int aX, int aY, int aWidth, int aHeight)
{
	if (m_Frames.count(aName) == 0)
	{
		m_Frames[aName].Set(aX, aY, aWidth, aHeight);
	}
}

void thomas::SpriteSheet::SetFrame(const std::string & aName)
{
	if (m_Frames.count(aName) > 0)
	{
		int x, y, w, h;
		m_Frames[aName].Get(&x, &y, &w, &h);
		m_Source.Set(x, y, w, h);
	}
}
