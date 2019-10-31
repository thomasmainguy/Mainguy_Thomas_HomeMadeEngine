#ifndef THOMAS_TRANSFORMABLE_H
#define THOMAS_TRANSFORMABLE_H

#include <string>
#include <Transform.h>

namespace thomas
{
	class Transformable : public Component
	{
	public:
		virtual ~Transformable() = default;
		virtual void Update(Transform* aTransform, float aDelta) = 0;
	};
}

#endif
