#pragma once
class Vertex
{
public:
	Vertex* _north = nullptr;
	Vertex* _south = nullptr;
	Vertex* _east  = nullptr;
	Vertex* _west  = nullptr;

	bool walkableNorth = false;
	bool walkableSouth = false;
	bool walkableEast  = false;
	bool walkableWest  = false;

	void connectNorth(Vertex* north)
	{
		this->_north = north;
		north->_south = this;
	}

	void connectSouth(Vertex* south)
	{
		this->_south = south;
		south->_north = this;
	}

	void connectEast(Vertex* east)
	{
		this->_east = east;
		east->_west = this;
	}

	void connectWest(Vertex* west)
	{
		this->_west = west;
		west->_east = this;
	}
};

