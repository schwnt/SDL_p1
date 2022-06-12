#include "core.h"

std::shared_ptr<STexture> texture;

Game::Game() {}
Game::~Game() {}

void Game::Init() {
	texture = std::make_shared<STexture>("res/game.png");
}
void Game::Continue() {}
void Game::Exit() {}

void Game::Render()
{
	SDL_RenderClear(gRenderer);
	texture->Render(gRenderer, NULL);
	SDL_RenderPresent(gRenderer);
}

void Game::Pause() {}

void Game::Update() {}

void Game::Start() {}