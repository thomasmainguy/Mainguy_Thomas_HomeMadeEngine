#include <Circle.h>

void thomas::Circle::Set(int aX, int aY, float aRadius)
{
	m_Position.x = aX;
	m_Position.y = aY;
	m_Radius = aRadius;

}

void thomas::Circle::Get(int * aX, int * aY, float * aRadius) const
{
	*aX = m_Position.x;
	*aY = m_Position.y;
	*aRadius = m_Radius;

}
