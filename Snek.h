#pragma once

#include <list>
#include "Limb.h"
#include "olcPixelGameEngine/olcPixelGameEngine.h"

class Snek
{
private:
	std::list<Limb> _snek;
	Limb _lastTailPos;

public:
	Snek() = default;
	~Snek() = default;

	std::list<Limb>::iterator begin()
	{
		return this->_snek.begin();
	}

	std::list<Limb>::iterator end()
	{
		return this->_snek.end();
	}

	Limb& getHead()
	{
		return this->_snek.front();
	}

	void moveTo(const Limb& l)
	{
		l.getVert()->hasLimb = true;
		this->_snek.push_front(l);
		if(l.getVert()->hasApple)
		{
			l.getVert()->hasApple = false;
			return;
		}

		// keep first limb, aka starting pos of head
		if(this->length() > 1)
		{
			this->_lastTailPos = this->_snek.back();
			this->_lastTailPos.getVert()->hasLimb = false;
			this->_snek.pop_back();
		}
	}

	size_t length()
	{
		return this->_snek.size();
	}
};
