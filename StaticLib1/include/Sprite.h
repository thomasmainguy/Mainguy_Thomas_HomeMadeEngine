#ifndef THOMAS_SPRITE_H
#define THOMAS_SPRITE_H

#include <Rectangle.h>
#include <string>
#include <GraphicComponent.h>

namespace thomas
{
	class Sprite : public GraphicComponent
	{
	public:
		virtual ~Sprite() = default;

		void Load(IGraphic& aGraphic, std::string& aFile) override;
		void Draw(IGraphic& aGraphic) override;
		void Update(Transform* aTransform, float aDelta) override;

	protected:
		unsigned int m_TextureId{ 0 };
		thomas::Rectangle m_Destination{};
		thomas::Rectangle m_Source{};
		float m_Angle{ 0.0f };
		bool m_Flip{ false };
		int m_Alpha{ 255 };
	};}

#endif