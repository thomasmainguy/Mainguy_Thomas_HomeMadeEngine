#ifndef THOMAS_RECTANGLE_H
#define THOMAS_RECTANGLE_H

#include <Point.h>

namespace thomas
{
	class Rectangle
	{
	public:
		void Set(int aX, int aY, int aWidth, int  aHeight);
		void Get(int* aX, int* aY, int* aWidth, int* aHeight) const;

	private:
		Point m_Position{};
		Point m_Size{};
	};
}
#endif // THOMAS_RECTANGLE_H

