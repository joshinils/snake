#pragma once

#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "Graph.h"
#include "Snek.h"

class Snake
{
private:
	// size, always even
	size_t _width;
	size_t _height;
	Graph _graph;
	olc::vi2d _apple;
	Snek _snek;

	bool lastDirectionNorth = false;
	bool lastDirectionEast  = false;
	bool lastDirectionSouth = false;
	bool lastDirectionWest  = false;

public:
	Snake(size_t width, size_t height);
	~Snake();

	static const size_t CellSizeHalf = 64;
	static const size_t CellSize = CellSizeHalf * 2;

	void draw(olc::PixelGameEngine* const pge);
	void iterate();

	olc::vi2d randomPos();
};

