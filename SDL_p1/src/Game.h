#pragma once

/* */
class Game
{
public:
	Game();
	~Game();

	void Init();

	void Update();
	void Render();

	void Start();
	void Pause();
	void Continue();
	void Exit();

};