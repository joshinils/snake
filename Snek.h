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
	Snek(Limb head)
		: _snek(1, head)
	{ }

	~Snek() = default;

	auto begin()
	{
		return this->_snek.begin();
	}

	auto end()
	{
		return this->_snek.end();
	}

	Limb& getHead()
	{
		return this->_snek.front();
	}

	void moveTo(const Limb& l)
	{
		this->_snek.push_front(l);
		_lastTailPos = this->_snek.back();
		this->_snek.pop_back();
	}

	void eatFrom(const Limb& l)
	{
		this->_snek.push_front(l);
	}
};
