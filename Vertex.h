#pragma once

#include "olcPixelGameEngine/olcPixelGameEngine.h"

class Vertex
{
public:
	olc::vi2d pos;

public:
	Vertex()
		: pos({-1, -1})
	{ }

	Vertex* north = nullptr;
	Vertex* south = nullptr;
	Vertex* east  = nullptr;
	Vertex* west  = nullptr;

	bool walkableNorth = false;
	bool walkableSouth = false;
	bool walkableEast  = false;
	bool walkableWest  = false;

	bool hasApple = false;
	bool hasLimb = false;

	void connectNorth(Vertex* north)
	{
		this->north = north;
		north->south = this;
	}

	void connectSouth(Vertex* south)
	{
		this->south = south;
		south->north = this;
	}

	void connectEast(Vertex* east)
	{
		this->east = east;
		east->west = this;
	}

	void connectWest(Vertex* west)
	{
		this->west = west;
		west->east = this;
	}

	/* north */
	bool unblockNorth()
	{
		if(this->north == nullptr) return false;
		this->walkableNorth = this->north->walkableSouth = true;
		return true;
	}

	bool blockNorth()
	{
		if(this->north == nullptr) return false;
		this->walkableNorth = this->north->walkableSouth = false;
		return true;
	}

	bool swapBlockNorth()
	{
		if(this->north == nullptr) return false;
		this->walkableNorth = this->north->walkableSouth = !this->walkableNorth;
		return true;
	}

	/* south */
	bool unblockSouth()
	{
		if(this->south == nullptr) return false;
		this->walkableSouth = this->south->walkableNorth = true;
		return true;
	}

	bool blockSouth()
	{
		if(this->south == nullptr) return false;
		this->walkableSouth = this->south->walkableNorth = false;
		return true;
	}

	bool swapBlockSouth()
	{
		if(this->south == nullptr) return false;
		this->walkableSouth = this->south->walkableNorth = !this->walkableSouth;
		return true;
	}

	/* east */
	bool unblockEast()
	{
		if(this->east == nullptr) return false;
		this->walkableEast = this->east->walkableWest = true;
		return true;
	}

	bool blockEast()
	{
		if(this->east == nullptr) return false;
		this->walkableEast = this->east->walkableWest = false;
		return true;
	}

	bool swapBlockEast()
	{
		if(this->east == nullptr) return false;
		this->walkableEast = this->east->walkableWest = !this->walkableEast;
		return true;
	}

	/* west */
	bool unblockWest()
	{
		if(this->west == nullptr) return false;
		this->walkableWest = this->west->walkableEast = true;
		return true;
	}

	bool blockWest()
	{
		if(this->west == nullptr) return false;
		this->walkableWest = this->west->walkableEast = false;
		return true;
	}

	bool swapBlockWest()
	{
		if(this->west == nullptr) return false;
		this->walkableWest = this->west->walkableEast = !this->walkableWest;
		return true;
	}
};

