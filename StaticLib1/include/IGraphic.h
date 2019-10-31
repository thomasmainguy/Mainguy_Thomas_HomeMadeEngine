#ifndef THOMAS_IGRAPHIC_H
#define THOMAS_IGRAPHIC_H

#include <IService.h>
#include <Rectangle.h>
#include <Point.h>
#include <Circle.h>
#include <string>

namespace thomas
{
	class IGraphic : public IService
	{
	public:
		virtual ~IGraphic() = default;
		virtual bool InitWindow(const std::string& aTitle, int aWidth, int aHeight) = 0;
		virtual void Clear() = 0;
		virtual void Present() = 0;
		virtual void SetColor(int aRed, int aGreen, int aBlue, int aAlpha) = 0;

		//Implementer dans SDLGraphic et dans NUllGraphic ou je perds des points pour rien

		//deux maps pour les textures et fonts
		virtual unsigned int LoadTexture(const std::string& aFilename) = 0; // donner le chemin et retourne le id pour sa position dans la map
		virtual unsigned int LoadFont(const std::string& aFilename) = 0;
		//map pour les size deja prises
		virtual void GetTextureSize(unsigned int aTexutreId, int* aWidth, int* aHeight) = 0;
		//same
		virtual void GetFontSize(unsigned int aFontId, const std::string& aText, int* aWidth, int* aHeight) = 0;


		virtual void Draw(const Rectangle& aRect) = 0;
		virtual void Draw(int aX, int aY, int aWidth, int aHeight) = 0;
		virtual void Draw(const Circle& aCircle) = 0;
		virtual void Draw(int aX, int aY, float aRadius) = 0;
		virtual void Draw(const Point& aPoint) = 0;
		virtual void Draw(int aX, int aY) = 0;


		//aSrc = la tialle de ma texture pour l'instant
		//aDst = destination dans l'ecran
		//Implementer dans SDLGraphic et dans NUllGraphic ou je perds des points pour rien
		virtual void Draw(unsigned int aTextureId, const Rectangle& aSrc, const Rectangle& aDst, float aAngle, bool aFlip, int aAlpha) = 0;
		virtual void Draw(unsigned int aFontId, const std::string& aText, int aX, int aY) = 0;
	}; 

	
}
#endif