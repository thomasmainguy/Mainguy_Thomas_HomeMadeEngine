#ifndef THOMAS_RECTANGLECOLLISION_H
#define THOMAS_RECTANGLECOLLISION_H

#include <Entity.h>
#include <Rectangle.h>
#include <Transform.h>
#include <Sprite.h>
#include <Collision.h>

namespace thomas
{
	class RectangleCollision : public thomas::Entity
	{
	public:
		virtual ~RectangleCollision() = default;

		void Update(float aDeltaTime) override;
		void Draw() override;

		bool CanDraw() override { return true; }
		bool CanUpdate() override { return true; }

		void Start() override;
		void Destroy() override;
		thomas::Rectangle GetEntityCollider() { return m_Collider; }

	private:
		float m_Speed{ 75.0f };
		Transform m_Transform;
		Sprite m_Sprite;

		Collision* m_Collision = nullptr;
		thomas::Rectangle m_Collider;
		unsigned int m_TextureId = 0;

	};
}
#endif
