#ifndef THOMAS_SDLGRAPHIC_H
#define THOMAS_SDLGRAPHIC_H

#include <IGraphic.h>
#include <map>

struct _TTF_Font;
struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Window;
struct SDL_Surface;
struct SDL_Color;

namespace thomas
{
	// Inherited via IGraphic
	class SDLGraphic final : public IGraphic
	{
	public:
		virtual ~SDLGraphic() = default;
		virtual bool Initialize() override;
		virtual void Clean() override;
		virtual bool InitWindow(const std::string & aTitle, int aWidth, int aHeight) override;
		virtual void Clear() override;
		virtual void Present() override;
		virtual void SetColor(int aRed, int aGreen, int aBlue, int aAlpha) override;
		
		virtual unsigned int LoadTexture(const std::string& aFilename) override; // donner le chemin et retourne le id pour sa position dans la map
		virtual unsigned int LoadFont(const std::string& aFilename) override;
		//map pour les size deja prises
		virtual void GetTextureSize(unsigned int aTexutreId, int* aWidth, int* aHeight) override;
		//same
		virtual void GetFontSize(unsigned int aFontId, const std::string& aText, int* aWidth, int* aHeight) override;
		
		virtual void Draw(const Rectangle & aRect) override;
		virtual void Draw(int aX, int aY, int aWidth, int aHeight) override;
		virtual void Draw(const Circle & aCircle) override;
		virtual void Draw(int aX, int aY, float aRadius) override;
		virtual void Draw(const Point & aPoint) override;
		virtual void Draw(int aX, int aY) override;
		void GetValues(int* aX, int* aY);

		virtual void Draw(unsigned int aTextureId, const Rectangle& aSrc, const Rectangle& aDst, float aAngle, bool aFlip, int aAlpha) override;
		virtual void Draw(unsigned int aFontId, const std::string& aText, int aX, int aY) override;

	
	private:

		//Screen dimension constants
		const int SCREEN_WIDTH = 900;
		const int SCREEN_HEIGHT = 900;
		const int m_RectWdt = 700;
		const int m_RectHgt = 700;

		int m_ImageWidth = 0;
		int m_ImageHeigth = 0;

		int m_FontWidth = 0;
		int m_FontHeigth = 0;
		SDL_Texture* m_Texture = nullptr;

		typedef std::map<unsigned int, SDL_Texture*> TTextureMap;
		typedef std::map<unsigned int, _TTF_Font*> TFont;

		TTextureMap m_TextureCache;
		TFont m_FontCache;
		SDL_Surface* m_Surface = nullptr;
		SDL_Renderer* m_Board = nullptr;
		SDL_Window* m_Window = nullptr;
	};

}
#endif

