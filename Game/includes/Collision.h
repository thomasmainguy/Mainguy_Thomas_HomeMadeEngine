#ifndef THOMAS_COLLISION_H
#define THOMAS_COLLISION_H

#include <Entity.h>
#include <Rectangle.h>
#include <Transform.h>
#include <Sprite.h>

namespace thomas
{
	class Collision : public thomas::Entity
	{
	public:
		virtual ~Collision() = default;

		void Update(float aDeltaTime) override;
		void Draw() override;

		bool CanDraw() override { return true; }
		bool CanUpdate() override { return true; }

		void Start() override;
		void Destroy() override;
		thomas::Rectangle GetEntityCollider() { return m_Collider; }

	private:
		Transform m_Transform;
		Sprite m_Sprite;

		thomas::Rectangle m_Collider;



		unsigned int m_TextureId = 0;

	};
}
#endif
