#include "NullCollider.h"

bool thomas::NullCollider::Initialize()
{
	return true;
}

void thomas::NullCollider::Clean()
{
}

bool thomas::NullCollider::IsColliding(const Rectangle & aRectA, const Rectangle & aRectB)
{
	return false;
}

bool thomas::NullCollider::IsColliding(const Circle & aCircleA, const Circle & aCircleB)
{
	return false;
}

bool thomas::NullCollider::IsColliding(const Circle & aCircle, const Rectangle & aRect)
{
	return false;
}
