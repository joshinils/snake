#pragma once

#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "Vertex.h"

class Limb
{
private:
	olc::vi2d _pos;
	Vertex* _vert;

public:
	Limb(olc::vi2d pos = {-1, -1}, Vertex* vert = nullptr)
		: _pos(pos)
		, _vert(vert)
	{ }

	~Limb() = default;

	Vertex* getVert() const
	{
		return _vert;
	}

	olc::vi2d getPos() const
	{
		return _pos;
	}
};
