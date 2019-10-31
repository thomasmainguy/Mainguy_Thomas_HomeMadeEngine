#include "..\include\ColliderManager.h"
#include <math.h>
#include <Engine.h>

bool thomas::ColliderManager::Initialize()
{
	return true;
}

void thomas::ColliderManager::Clean()
{
}

bool thomas::ColliderManager::IsColliding(const Rectangle & aRectA, const Rectangle & aRectB)
{
	int x1, y1, w1, h1;
	aRectA.Get(&x1, &y1, &w1, &h1);

	int x2, y2, w2, h2;
	aRectB.Get(&x2, &y2, &w2, &h2);

	if (x1 < (x2 + w2) && (x1 + w1) > x2 && y1 < (y2 + h2) && (y1 + h1) > y2)
	{
		return true;
	}
	return false;
}

bool thomas::ColliderManager::IsColliding(const Circle & aCircleA, const Circle & aCircleB)
{
	int xC1, yC1;
	float r1;
	aCircleA.Get(&xC1, &yC1, &r1);

	int xC2, yC2;
	float r2;
	aCircleB.Get(&xC2, &yC2, &r2);

	float a, b, c;
	a = abs(yC1 - yC2);
	b = abs(xC1 - xC2);
	c = sqrt(a*a + b*b);

	if (c < (r1 + r2))
	{
		return true;
	}

	return false;
}

bool thomas::ColliderManager::IsColliding(const Circle & aCircle, const Rectangle & aRect)
{
	
	int x, y, w, h;
	aRect.Get(&x, &y, &w, &h);

	int xC, yC;
	float r;
	aCircle.Get(&xC, &yC, &r);

	thomas::Circle tCircleSmall;
	thomas::Circle tCircleBig;
	tCircleSmall.Set(x + w / 2, y + h / 2, w / 2);

	float tr = 0.0f;
	if (w > h)
	{
		float  a, b;
		a = abs((w / 2) * (w / 2));
		b = abs((w / 2) * (w / 2));
		tr = sqrt(a + b);
	}
	else
	{
		float  a, b;
		a = abs((h / 2) * (h / 2));
		b = abs((h / 2) * (h / 2));
		tr = sqrt(a + b);
	}

	tCircleBig.Set(x + w / 2, y + h / 2, tr);

	thomas::Engine::Instance().GetGraphic().SetColor(0, 255, 0, 255);
	thomas::Engine::Instance().GetGraphic().Draw(tCircleSmall);
	thomas::Engine::Instance().GetGraphic().SetColor(0, 255, 0, 255);
	thomas::Engine::Instance().GetGraphic().Draw(tCircleBig);


	if (IsColliding(aCircle, tCircleSmall))
	{
		return true;
	}
	else if(IsColliding(aCircle, tCircleBig))
	{
		int  a, b;
		float c;

		a = abs((xC - x) * (xC - x));
		b = abs((yC - y) * (yC - y));
		c = sqrt(a + b);

		if(c < r)
		{
			return true;
		}

		a = abs((xC - (x + w)) * (xC - (x + w)));
		b = abs((yC - (y + h)) * (yC - (y + h)));
		c = sqrt(a + b);

		if (c < r)
		{
			return true;
		}

		a = abs((xC - (x + w)) * (xC - (x + w)));
		b = abs((yC - y) * (yC - y));
		c = sqrt(a + b);

		if (c < r)
		{
			return true;
		}

		a = abs((xC - x) * (xC - x));
		b = abs((yC - (y + h)) * (yC - (y + h)));
		c = sqrt(a + b);

		if (c < r)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}
