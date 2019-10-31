#ifndef THOMAS_ICOLLIDER_H
#define THOMAS_ICOLLIDER_H

#include <IService.h>
#include <string>
#include <Rectangle.h>
#include <Circle.h>

namespace thomas
{
	class ICollider : public IService
	{
	public:
		virtual ~ICollider() = default;
		
		virtual bool IsColliding(const Rectangle& aRectA, const Rectangle& aRectB) = 0;
		virtual bool IsColliding(const Circle& aCircleA, const Circle& aCircleB) = 0;
		virtual bool IsColliding(const Circle& aCircle, const Rectangle& aRect) = 0;
	};
}

#endif
