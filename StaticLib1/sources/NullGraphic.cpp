#include "NullGraphic.h"

bool thomas::NullGraphic::InitWindow(const std::string & aTitle, int aWidth, int aHeight)
{
	return true;
}

void thomas::NullGraphic::Clean()
{
}


bool thomas::NullGraphic::Initialize()
{
	return true;
}

void thomas::NullGraphic::Clear()
{
}

unsigned int thomas::NullGraphic::LoadTexture(const std::string & aFilename)
{
	return 0;
}

unsigned int thomas::NullGraphic::LoadFont(const std::string & aFilename)
{
	return 0;
}

void thomas::NullGraphic::GetTextureSize(unsigned int aTexutreId, int * aWidth, int * aHeight)
{
}

void thomas::NullGraphic::GetFontSize(unsigned int aFontId, const std::string & aText, int * aWidth, int * aHeight)
{
}

void thomas::NullGraphic::Present()
{
}

void thomas::NullGraphic::SetColor(int aRed, int aGreen, int aBlue, int aAlpha)
{
}




void thomas::NullGraphic::Draw(const Rectangle & aRect)
{
}

void thomas::NullGraphic::Draw(int aX, int aY, int aWidth, int aHeight)
{
}

void thomas::NullGraphic::Draw(const Circle & aCircle)
{
}

void thomas::NullGraphic::Draw(int aX, int aY, float aRadius)
{
}

void thomas::NullGraphic::Draw(const Point & aPoint)
{
}

void thomas::NullGraphic::Draw(int aX, int aY)
{
}

void thomas::NullGraphic::Draw(unsigned int aTextureId, const Rectangle & aSrc, const Rectangle & aDst, float aAngle, bool aFlip, int aAlpha)
{
}

void thomas::NullGraphic::Draw(unsigned int aFontId, const std::string & aText, int aX, int aY)
{
}
