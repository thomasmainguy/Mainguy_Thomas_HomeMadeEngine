#ifndef THOMAS_BACKGROUND_H
#define THOMAS_BACKGROUND_H

#include <Entity.h>
#include <Rectangle.h>

namespace thomas
{
	class BackGround : public thomas::Entity
	{
	public:
		virtual ~BackGround() = default;
		void Update(float aDeltaTime) override;
		void Draw() override;

		bool CanDraw() override { return true; }
		bool CanUpdate() override { return false; }

		void Start() override;
		void Destroy() override;

	private:
		thomas::Rectangle m_Rect;
		unsigned int m_MusicId = 0;
		unsigned int m_BackGroundId = 0;
	};
}

#endif 
