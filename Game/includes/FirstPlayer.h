#ifndef THOMAS_FIRSTPLAYER_H
#define THOMAS_FIRSTPLAYER_H

#include <Entity.h>
#include <Rectangle.h>
#include <Transform.h>
#include <Sprite.h>
#include <Collision.h>
#include <SpriteSheet.h>
#include <Animation.h>

namespace thomas
{
	class FirstPlayer : public thomas::Entity
	{
	public:
		virtual ~FirstPlayer() = default;

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
		SpriteSheet m_SpriteSheet;
		float m_Speed{ 75.0f };
		Animation m_Animateur;

		thomas::Rectangle m_Collider;
		Collision* m_Collision = nullptr;
		unsigned int m_TextureId = 0;
		unsigned int m_SoundId = 0;

	};
}
#endif // !PLAYER_H