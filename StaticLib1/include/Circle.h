#ifndef THOMAS_CIRCLE_H
#define THOMAS_CIRCLE_H

#include <Point.h>

namespace thomas
{
	class Circle
	{
	public:
		void Set(int aX, int aY, float aRadius);
		void Get(int* aX, int* aY, float* aRadius) const;

	private:
		Point m_Position{};
		float m_Radius{ 0.0f };
	};
}
#endif;
