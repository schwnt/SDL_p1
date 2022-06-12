#include "core.h"


#define FRAME_TIME = (Uint32)1000/60

SDL_Window* gWindow;
SDL_Renderer* gRenderer;
TTF_Font* gFont;
/*drawing color*/
SDL_Color dColor;

enum class State
{
	PLAY,
	MENU
};

int main(int argc, char* args[])
{
	int winW = 1250;
	int winH = 800;

	InitWindow(winW, winH);


	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	Timer timer;

	STexture imgtest("res/a.png");
	SDL_Color red{ 0, 0, 0, 255 };
	STexture texttest(gFont, "THTHTHTHTH", red);
	SDL_Rect r1{ 0,0,imgtest.w, imgtest.h };
	SDL_Rect r2{ 100, 100, texttest.w, texttest.h };

	SDL_SetRenderDrawColor(gRenderer, dColor.r, dColor.g, dColor.b, dColor.a);

	auto menu(std::make_unique<Menu>());

	menu->Init();

	auto game(std::make_unique<Game>());

	game->Init();

	State state = State::MENU;

	

	while (!quit)
	{
		timer.SetFrameStart();

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}


		switch (state)
		{
		case State::PLAY:
			game->Update();
			game->Render();
			break;
		case State::MENU:
			menu->Update();
			menu->Render();
		default:
			break;
		}

		auto currentKeyStates = SDL_GetKeyboardState(NULL);

		/* state switch */
		if (state == State::PLAY && 
			!currentKeyStates[SDL_SCANCODE_ESCAPE]) 
		{
			// do nothing
		}
		else
		{
			switch (state)
			{
			case State::PLAY: //currentKeyStates[ESC] == true
				state = State::MENU;
				game->Pause();
				break;

			case State::MENU:
				if (menu->unpause) {
					state = State::PLAY;
					menu->unpause = false;
					game->Continue();
				}
				else if (menu->gameExit)
				{
					menu->gameExit = false;
					game->Exit();
				}
				else if (menu->gameStart)
				{
					state = State::PLAY;
					menu->gameStart = false;
					game->Start();
				}
				break;

			default:
				break;
			}
		}


		/*cap frame*/
		if (timer.GetFrameTime() < (1000 / 60))
		{
			timer.extra += (1000 / 60) - timer.GetFrameTime();
			SDL_Delay((1000 / 60) - timer.GetFrameTime());
		}
	}

	std::cout << timer.extra;

	Close();
	return 0;
}

