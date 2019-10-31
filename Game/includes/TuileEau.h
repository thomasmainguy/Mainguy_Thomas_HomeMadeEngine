#ifndef THOMAS_TUILEEAU_H
#define THOMAS_TUILEEAU_H

#include <Entity.h>
#include <Rectangle.h>
#include <Transform.h>
#include <Sprite.h>
#include <Collision.h>
#include <SpriteSheet.h>

namespace thomas
{
	class TuileEau : public thomas::Entity
	{
	public:
		virtual ~TuileEau() = default;

		void Update(float aDeltaTime) override;
		void Draw() override;

		bool CanDraw() override { return true; }
		bool CanUpdate() override { return true; }

		void Start() override;
		void Destroy() override;

	private:
		Transform m_Transform;

		SpriteSheet m_SpriteSheet;
	};
}
#endif // !PLAYER_H
