#include "..\include\Rectangle.h"

void thomas::Rectangle::Set(int aX, int aY, int aWidth, int aHeight)
{
	m_Position.x = aX;
	m_Position.y = aY;
	m_Size.x = aWidth;
	m_Size.y = aHeight;
}

void thomas::Rectangle::Get(int * aX, int * aY, int * aWidth, int * aHeight) const
{
	*aX = m_Position.x;
	*aY = m_Position.y;
	*aWidth = m_Size.x;
	*aHeight = m_Size.y;
	
}	
	