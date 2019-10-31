#ifndef THOMAS_COLLIDERMANAGER_H
#define THOMAS_COLLIDERMANAGER_H

#include <ICollider.h>
#include <string>

namespace thomas
{
	class ColliderManager final : public ICollider
	{
	public:
		virtual ~ColliderManager() = default;

		virtual bool Initialize() override;
		virtual void Clean() override;

		virtual bool IsColliding(const Rectangle & aRectA, const Rectangle & aRectB) override;

		virtual bool IsColliding(const Circle & aCircleA, const Circle & aCircleB) override;

		virtual bool IsColliding(const Circle & aCircle, const Rectangle & aRect) override;

	};
}
#endif
