#ifndef THOMAS_TRANSFORM_H
#define THOMAS_TRANSFORM_H

#include <Component.h>
#include <string>

namespace thomas
{
	class Transform final: public Component
	{
	public:
		virtual ~Transform() = default;

		void SetPosition(float aX, float aY);
		void Translate(float aX, float aY);
		void SetRotation(float aAngle);
		void Rotate(float aAngle);
		void SetWidth(float aWidth);
		void SetHeight(float aHeight);
		void SetFlip(bool aFlip);

		float X{ 0.0f };
		float Y{ 0.0f };
		float Angle{ 0.0f };
		float Width{ 100.0f };
		float Height{ 100.0f };
		bool Flipped{ false };
	};
}

#endif
