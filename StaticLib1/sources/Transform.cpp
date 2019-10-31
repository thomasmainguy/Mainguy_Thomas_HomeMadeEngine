#include "..\include\Transform.h"

void thomas::Transform::SetPosition(float aX, float aY)
{
	X = aX;
	Y = aY;
}

void thomas::Transform::Translate(float aX, float aY)
{
	X += aX;
	Y += aY;
}

void thomas::Transform::SetRotation(float aAngle)
{
	Angle = aAngle;
	while (aAngle > 360.0f)
	{
		aAngle = aAngle - 360;
	}
}

void thomas::Transform::Rotate(float aAngle)
{
	Angle += aAngle;
	while (aAngle > 360.0f)
	{
		aAngle = aAngle - 360;
	}
}

void thomas::Transform::SetWidth(float aWidth)
{
	Width = aWidth;
}

void thomas::Transform::SetHeight(float aHeight)
{
	Height = aHeight;
}

void thomas::Transform::SetFlip(bool aFlip)
{
	Flipped = aFlip;
}
