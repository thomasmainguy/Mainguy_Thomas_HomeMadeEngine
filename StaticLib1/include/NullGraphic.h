#ifndef THOMAS_NULLGRAPHIC_H
#define THOMAS_NULLGRAPHIC_H

#include <IGraphic.h>


struct SDL_RendererFlip;

namespace thomas
{
	class NullGraphic final : public IGraphic
	{
	public:
		
		virtual ~NullGraphic() = default;

		virtual bool Initialize() override;
		virtual void Clean() override;

		virtual bool InitWindow(const std::string& aTitle, int aWidth, int aHeight) override;
		virtual void Clear() override;

		virtual unsigned int LoadTexture(const std::string& aFilename) override; // donner le chemin et retourne le id pour sa position dans la map
		virtual unsigned int LoadFont(const std::string& aFilename) override;
		//map pour les size deja prises
		virtual void GetTextureSize(unsigned int aTexutreId, int* aWidth, int* aHeight) override;
		//same
		virtual void GetFontSize(unsigned int aFontId, const std::string& aText, int* aWidth, int* aHeight) override;


		virtual void Present() override;
		virtual void SetColor(int aRed, int aGreen, int aBlue, int aAlpha) override;
		virtual void Draw(const Rectangle& aRect) override;
		virtual void Draw(int aX, int aY, int aWidth, int aHeight) override;
		virtual void Draw(const Circle& aCircle) override;
		virtual void Draw(int aX, int aY, float aRadius) override;
		virtual void Draw(const Point& aPoint) override;
		virtual void Draw(int aX, int aY) override;

		virtual void Draw(unsigned int aTextureId, const Rectangle& aSrc, const Rectangle& aDst, float aAngle, bool aFlip, int aAlpha) override;
		virtual void Draw(unsigned int aFontId, const std::string& aText, int aX, int aY) override;

	
	};
}
#endif