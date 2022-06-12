#include "core.h"



SDL_Texture* StringToTexture(std::string textureText, SDL_Color textColor)
{
    //Get rid of preexisting texture

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    SDL_Texture* retTexture;
    if (textSurface == NULL) return NULL;
    else
    {
        //Create texture from surface pixels
        retTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (retTexture == NULL) return NULL;

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return retTexture;
}


STexture::STexture(std::string path)
{
    Free();
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) return;

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

	texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

	w = loadedSurface->w;
	h = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);
}

STexture::STexture(TTF_Font* font, std::string text, SDL_Color color)
{
	Free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text.c_str(), color);
	if (textSurface == NULL) return;

	
	//Create texture from surface pixels
	texture = SDL_CreateTextureFromSurface(gRenderer, textSurface);

	w = textSurface->w;
	h = textSurface->h;

	//Get rid of old surface
	SDL_FreeSurface(textSurface);

}

STexture::~STexture()
{
    Free();
}