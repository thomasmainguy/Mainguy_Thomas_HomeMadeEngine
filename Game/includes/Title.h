#ifndef THOMAS_TITLE_H
#define THOMAS_TITLE_H

#include <Entity.h>
#include <Rectangle.h>

struct SDL_Texture;
struct SDL_Surface;


namespace thomas
{
	class Title : public thomas::Entity
	{
	public:
		virtual ~Title() = default;
		void Update(float aDeltaTime) override;
		void Draw() override;

		bool CanDraw() override { return true; }
		bool CanUpdate() override { return true; }

		void Start() override;
		void Destroy() override;

	private:
		const std::string m_Instructions = "Press F to load next scene";

		unsigned int m_FontId = 0;
	};
}

#endif 
