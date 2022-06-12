#include "ex.h"

class Timer
{
public:
	Timer();

	/*ticks passed since last time this called*/
	Uint32 GetTicks();
	void SetFrameStart();
	Uint32 GetFrameTime();

	Uint32 extra;
private:
	Uint32 start;
	Uint32 lastFrame;

};

Timer::Timer()
{
	start = SDL_GetTicks();
	lastFrame = start;
	extra = 0;
}

void Timer::SetFrameStart()
{
	lastFrame = SDL_GetTicks();
}

Uint32 Timer::GetFrameTime()
{
	return SDL_GetTicks() - lastFrame;
}

Uint32 Timer::GetTicks()
{
	Uint32 time = SDL_GetTicks() - lastFrame;
	lastFrame = SDL_GetTicks();
	return time;
}

