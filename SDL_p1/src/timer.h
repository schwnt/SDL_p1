#pragma once
#include "ex.h";

class Timer
{
public:
	Timer();

	/*ticks passed since last time this or SetFrame called*/
	Uint32 GetTicks();
	void SetFrameStart();
	Uint32 GetFrameTime();
	Uint32 extra;
private:
	Uint32 start;
	Uint32 lastFrame;
};

inline double TickToFrame(Uint32 ticks)
{
	return ticks / 1000.f;
}