#ifndef THOMAS_SPRITESHEET_H
#define THOMAS_SPRITESHEET_H

#include <Sprite.h>
#include <string>
#include <map>

namespace thomas
{
	class SpriteSheet final : public Sprite
	{
	public:
		virtual ~SpriteSheet() = default;

		void AddFrame(const std::string& aName, int aX, int aY, int aWidth, int aHeight);
		void SetFrame(const std::string& aName);

	private:
		std::map<std::string, Rectangle> m_Frames;
	};
}
#endif

