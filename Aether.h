#ifndef AETHER_H
#define AETHER_H

#include "olcPixelGameEngine/olcPixelGameEngine.h"

class Aether
	: public olc::PixelGameEngine
{

private:

public:
	Aether();
	~Aether();

	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);

private:

};

#endif // AETHER_H
