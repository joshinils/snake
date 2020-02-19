#pragma once

#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "Graph.h"
#include <list>

class Snake
{
private:
	// size, always even
	size_t _width;
	size_t _height;
	Graph _graph;
	olc::vi2d _apple;
	std::list<olc::vi2d> _snek;

public:
	Snake(size_t width, size_t height);
	~Snake();

	static const size_t CellSizeHalf = 32;
	static const size_t CellSize = CellSizeHalf * 2;

	void draw(olc::PixelGameEngine* const pge);
	void iterate();

	olc::vi2d randomPos();
};

