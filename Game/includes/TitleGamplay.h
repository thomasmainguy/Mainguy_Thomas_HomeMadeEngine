#ifndef THOMAS_TITLEGAMEPLAY_H
#define THOMAS_TITLEGAMEPLAY_H

#include <Entity.h>
#include <Rectangle.h>

struct SDL_Texture;
struct SDL_Surface;


namespace thomas
{
	class TitleGamplay : public thomas::Entity
	{
	public:
		virtual ~TitleGamplay() = default;
		void Update(float aDeltaTime) override;
		void Draw() override;

		bool CanDraw() override { return true; }
		bool CanUpdate() override { return false; }

		void Start() override;
		void Destroy() override;

	private:
		const std::string m_Title = "click down WASD to move";
		SDL_Surface* m_Surface;
		int m_W, m_H;

		unsigned int m_FontId = 0;
	};
}

#endif 
