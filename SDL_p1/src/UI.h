#pragma once

class Menu
{
public:
	Menu();
	~Menu();

	void Init();

	void Render();
	void Update();

	void MainUpdate();
	void MainRender();

	void PauseUpdate();
	void PauseRender();

	
	bool unpause = false;
	bool gameExit = false;
	bool gameStart = false;

	
private:
	enum class Scene
	{
		Main,
		Pause
	} scene = Scene::Main;
	
};

