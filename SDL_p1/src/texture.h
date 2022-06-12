#pragma once
#include "ex.h"


SDL_Texture* StringToTexture(std::string textureText, SDL_Color textColor);

void FreeTexture(SDL_Texture* t);

/*Simple Texture*/
class STexture
{
public:
	STexture(std::string path);
	STexture(TTF_Font* font, std::string text, SDL_Color color);
	~STexture();

	inline bool Valid() { return texture != NULL; }

	inline void Free()
	{
		if (Valid()) return;
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
	
	inline void RenderEX(SDL_Renderer* renderer, SDL_Rect* drect, double angle, SDL_Point* center, SDL_RendererFlip flip)
	{
		SDL_RenderCopyEx(renderer, texture, 0, drect, angle, center, flip);
	}

	inline void Render(SDL_Renderer* renderer, SDL_Rect* drect)
	{
		SDL_RenderCopy(renderer, texture, 0, drect);
	}

	SDL_Texture* texture = NULL;
	int w, h;
};