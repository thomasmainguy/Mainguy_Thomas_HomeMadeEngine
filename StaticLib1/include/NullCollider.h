#ifndef THOMAS_NULLCOLLIDER_H
#define THOMAS_NULLCOLLIDER_H

#include <ICollider.h>
#include <string>

namespace thomas
{
	class NullCollider final : public ICollider
	{
	public:
		virtual ~NullCollider() = default;
		virtual bool Initialize() override;
		virtual void Clean() override;

		virtual bool IsColliding(const Rectangle & aRectA, const Rectangle & aRectB) override;

		virtual bool IsColliding(const Circle & aCircleA, const Circle & aCircleB) override;

		virtual bool IsColliding(const Circle & aCircle, const Rectangle & aRect) override;

	};
}
#endif