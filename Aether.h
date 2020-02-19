#ifndef AETHER_H
#define AETHER_H

#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "Snake.h"

class Aether
	: public olc::PixelGameEngine
{

private:
	Snake _snake;

public:
	Aether(size_t width, size_t height);
	~Aether();

	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);

private:

};

#endif // AETHER_H
