#include <SDLGraphic.h>
#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <Log.h>
#include <SDL_image.h>
#include <HashKey.h>
#include <SDL_ttf.h>
#include <Engine.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL.h>
#include <stdlib.h>



bool thomas::SDLGraphic::Initialize()
{
	return true;
}

void thomas::SDLGraphic::Clean()
{

	TTextureMap::iterator itr;
	for (itr = m_TextureCache.begin(); itr != m_TextureCache.end(); ++itr)
	{
		SDL_DestroyTexture(itr->second);
	}

	TFont::iterator itrr;
	for (itrr = m_FontCache.begin(); itrr != m_FontCache.end(); ++itrr)
	{
		TTF_CloseFont(itrr->second);
	}

	m_TextureCache.clear();
	m_FontCache.clear();

	SDL_FreeSurface(m_Surface);
	SDL_DestroyRenderer(m_Board);
	SDL_DestroyWindow(m_Window);
	
	SDL_Quit();
	TTF_Quit();
}

bool thomas::SDLGraphic::InitWindow(const std::string & aTitle, int aWidth, int aHeight)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		thomas::Engine::Instance().GetLog().LogUsingVS("SDL not initialized\n");
		return false;
	}
	else
	{
		int tResult = TTF_Init();
		//Create window
		m_Window = SDL_CreateWindow(aTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_Window == nullptr)
		{
			thomas::Engine::Instance().GetLog().LogUsingVS("Window could not be created!\n");
			return false;
		}
		else
		{
			m_Board = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
			return true;
		}
	}
	return false;
}

void thomas::SDLGraphic::Clear()
{
	SDL_RenderClear(m_Board);
}

void thomas::SDLGraphic::Present()
{
	SDL_RenderPresent(m_Board);
}

void thomas::SDLGraphic::SetColor(int aRed, int aGreen, int aBlue, int aAlpha)
{
	SDL_SetRenderDrawColor(m_Board, aRed, aGreen, aBlue, aAlpha);
}

unsigned int thomas::SDLGraphic::LoadTexture(const std::string & aFilename)
{
	const unsigned int tHashValue = thomas::HashKey::Generate(aFilename.c_str());

	if (m_TextureCache.count(tHashValue) > 0)
	{
		return tHashValue;
	}

	SDL_Surface* tTempSurface = IMG_Load(aFilename.c_str());
	if (tTempSurface == nullptr)
	{
		//log erreur
		thomas::Engine::Instance().GetLog().LogUsingVS("The texture youre trying to load is null");
		return 0;
	}

	SDL_Texture* tTexture = SDL_CreateTextureFromSurface(m_Board, tTempSurface);
	SDL_FreeSurface(tTempSurface);

	if (tTexture != nullptr)
	{
		m_TextureCache[tHashValue] = tTexture;
		return tHashValue;
	}

	return 0;
}

unsigned int thomas::SDLGraphic::LoadFont(const std::string & aFilename)
{
	const unsigned int tHashValue = thomas::HashKey::Generate(aFilename.c_str());

	if (m_FontCache.count(tHashValue) > 0)
	{
		return tHashValue;
	}
	else
	{
		_TTF_Font* tFont = TTF_OpenFont(aFilename.c_str(), 18);
		if (!tFont)
		{
			thomas::Engine::Instance().GetLog().LogUsingVS("Font is not initialized");
		}
		else
		{
			m_FontCache[tHashValue] = tFont;
			return tHashValue;
		}
	}
	return 0;
}

void thomas::SDLGraphic::GetTextureSize(unsigned int aTexutreId, int * aWidth, int * aHeight)
{
	SDL_QueryTexture(m_TextureCache.find(aTexutreId)->second, NULL, NULL, aWidth, aHeight);
}

void thomas::SDLGraphic::GetFontSize(unsigned int aFontId, const std::string & aText, int * aWidth, int * aHeight)
{
	TTF_SizeText(m_FontCache.find(aFontId)->second, aText.c_str(), aWidth, aHeight);
}

void thomas::SDLGraphic::Draw(const Rectangle & aRect)
{
	SDL_Rect tRect;
	aRect.Get(&tRect.x, &tRect.y, &tRect.w, &tRect.h);

	SDL_RenderDrawRect(m_Board, &tRect);
}

void thomas::SDLGraphic::Draw(int aX, int aY, int aWidth, int aHeight)
{
	SDL_Rect tRect;
	tRect.x = aX;
	tRect.y = aY;
	tRect.h = aHeight;
	tRect.w = aWidth;

	SDL_RenderDrawRect(m_Board, &tRect);
}

void thomas::SDLGraphic::Draw(const Circle & aCircle)
{
	int tPosX = 0, tPosY = 0;
	float tRadius = 0;
	aCircle.Get(&tPosX, &tPosY, &tRadius);
	Draw(tPosX, tPosY, tRadius);
}

void thomas::SDLGraphic::Draw(int aX, int aY, float aRadius)
{
	int d = (5 - aRadius * 4) / 4;
	int x = 0;
	int y = aRadius;
	do 
	{
		SDL_RenderDrawPoint(m_Board, aX + x, aY + y);
		SDL_RenderDrawPoint(m_Board, aX + x, aY - y);
		SDL_RenderDrawPoint(m_Board, aX - x, aY + y);
		SDL_RenderDrawPoint(m_Board, aX - x, aY - y);
		SDL_RenderDrawPoint(m_Board, aX + y, aY + x);
		SDL_RenderDrawPoint(m_Board, aX + y, aY - x);
		SDL_RenderDrawPoint(m_Board, aX - y, aY + x);
		SDL_RenderDrawPoint(m_Board, aX - y, aY - x);

		if (d < 0) 
		{
			d += 2 * x + 1;
		}
		else 
		{
			d += 2 * (x - y) + 1;
			y--;
		}
		x++;
	} while (x <= y);
}

void thomas::SDLGraphic::Draw(const Point & aPoint)
{
	SDL_RenderDrawPoint(m_Board, aPoint.x, aPoint.y);
}

void thomas::SDLGraphic::Draw(int aX, int aY)
{
	SDL_RenderDrawPoint(m_Board, aX, aY);
}

void thomas::SDLGraphic::GetValues(int * aX, int * aY)
{
	*aX = m_RectWdt;
	*aY = m_RectHgt;
}

void thomas::SDLGraphic::Draw(unsigned int aTextureId, const Rectangle & aSrc, const Rectangle & aDst, float aAngle, bool aFlip, int aAlpha)
{
	SDL_Rect tRect1;
	aSrc.Get(&tRect1.x, &tRect1.y, &tRect1.w, &tRect1.h);

	SDL_Rect tRect2;
	aDst.Get(&tRect2.x, &tRect2.y, &tRect2.w, &tRect2.h);

	SDL_RendererFlip tFlip = SDL_FLIP_NONE;

	if (aFlip)
	{
		tFlip = SDL_FLIP_HORIZONTAL;
	}


	SDL_RenderCopyEx(m_Board, m_TextureCache[aTextureId], &tRect1, &tRect2,(double)aAngle, nullptr, tFlip);
	SDL_SetTextureAlphaMod(m_TextureCache[aTextureId], aAlpha);
}

void thomas::SDLGraphic::Draw(unsigned int aFontId, const std::string & aText, int aX, int aY)
{
	SDL_Color tColor = { 150, 0, 50 };
	SDL_Rect tRect;
	int w, h;

	m_Surface = TTF_RenderText_Solid(m_FontCache[aFontId], aText.c_str(), tColor);
	if (m_Surface != nullptr)
	{
		m_Texture = SDL_CreateTextureFromSurface(m_Board, m_Surface);
		GetFontSize(aFontId, aText, &w, &h);
		tRect.x = aX;
		tRect.y = aY;
		tRect.h = h;
		tRect.w = w;

		SDL_RenderCopy(m_Board, m_Texture, nullptr, &tRect);
	}
	SDL_FreeSurface(m_Surface);
	SDL_DestroyTexture(m_Texture);
}
