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


	// returns if it has eaten an apple
	bool moveTo(const Limb& l)
	{
		l.getVert()->hasLimb = true;
		this->_snek.push_front(l);
		if(l.getVert()->hasApple)
		{
			l.getVert()->hasApple = false;
			return true;
		}

		// keep first limb, aka starting pos of head
		if(this->length() > 1)
		{
			if(this->_lastTailPos.getVert() != nullptr)
			{
				this->_lastTailPos.getVert()->hadTail = false;
			}
			this->_lastTailPos = this->_snek.back();
			this->_lastTailPos.getVert()->hasLimb = false;
			this->_lastTailPos.getVert()->hadTail = true;
			this->_snek.pop_back();
		}
		return false;
	}

	size_t length()
	{
		return this->_snek.size();
	}
};
