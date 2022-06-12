#include "core.h"



std::shared_ptr<STexture> mainmenu;
std::shared_ptr<STexture> pausemenu;


Menu::Menu() {}
Menu::~Menu() {}

void Menu::Init()
{
	pausemenu = std::make_shared<STexture>("res/pause.png");
	mainmenu = std::make_shared<STexture>("res/main.png");
}


void Menu::Update()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	switch (scene)
	{
	case Menu::Scene::Main:
		/* start new game */
		if (currentKeyStates[SDL_SCANCODE_E]) 
		{
			gameStart = true;

			scene = Scene::Pause;
		}
		break;

	case Menu::Scene::Pause:
		if (currentKeyStates[SDL_SCANCODE_E]) {
			unpause = true;
		}
		else if (currentKeyStates[SDL_SCANCODE_D]) {
			scene = Scene::Main;
		}
		break;

	default:
		break;
	}
}

void Menu::Render()
{
	SDL_RenderClear(gRenderer);

	switch (scene)
	{
	case Menu::Scene::Main:
		mainmenu->Render(gRenderer, NULL);
		break;

	case Menu::Scene::Pause:
		pausemenu->Render(gRenderer, NULL);
		break;

	default:
		break;
	}

	SDL_RenderPresent(gRenderer);
}