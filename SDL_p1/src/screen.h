#pragma once

#include "ex.h"


enum class ScreenDiv
{
	CENTER,
	TOP_LEFT,
	DOWN_RIGHT,
	ABOVE,
	BOTTOM
};

class Screen
{
public:
	Screen(int w, int h);
	~Screen();

	void SetSize(int w, int h);

	/*size of rendered element*/
	void GetPos(ScreenDiv div, int w = 0, int h = 0);

	int w, h;

};