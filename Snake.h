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

	// constants for drawing
	static const size_t cellSizeHalf;
	static const size_t cellSize;
	static const uint8_t opacity;
	static const double limbSizeMult;

	void draw(olc::PixelGameEngine* const pge);
	bool iterate();

	olc::vi2d randomPos();
};

