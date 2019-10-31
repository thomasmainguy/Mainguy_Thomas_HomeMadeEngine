#ifndef THOMAS_CIRCLEPLAYER_H
#define THOMAS_CIRCLEPLAYER_H

#include <Entity.h>
#include <Rectangle.h>
#include <Transform.h>
#include <Sprite.h>
#include <Collision.h>

namespace thomas
{
	class CirclePlayer : public thomas::Entity
	{
	public:
		virtual ~CirclePlayer() = default;

		void Update(float aDeltaTime) override;
		void Draw() override;

		bool CanDraw() override { return true; }
		bool CanUpdate() override { return true; }

		void Start() override;
		void Destroy() override;
		thomas::Circle GetEntityCollider() { return m_Collider; }

	private:
		Transform m_Transform;
		Sprite m_Sprite;
		float m_Speed{ 75.0f };

		thomas::Circle m_Collider;
		Collision* m_Collision = nullptr;
		unsigned int m_TextureId = 0;
		unsigned int m_SoundId = 0;

	};
}
#endif // !PLAYER_H
