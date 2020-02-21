#pragma once

#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "Vertex.h"

class Limb
{
private:
	Vertex* _vert;

public:
	Limb(Vertex* vert = nullptr)
		: _vert(vert)
	{ }

	~Limb() = default;

	Vertex* getVert() const
	{
		return _vert;
	}

	olc::vi2d getPos() const
	{
		return this->_vert->pos;
	}

	// initialize vertex if it is nullptr
	bool setVert(Vertex* vert)
	{
		if(this->_vert == nullptr)
		{
			_vert = vert;
			return true;
		}
		return false;
	}
};
