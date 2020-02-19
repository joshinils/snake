#include "Snake.h"
#include <cassert>
#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include <stdlib.h>

olc::vi2d Snake::randomPos()
{
	static double foo = this->_width / (double)RAND_MAX;
	static double bar = this->_height / (double)RAND_MAX;

	return olc::vi2d( std::rand() * foo, std::rand() * bar);
}

Snake::Snake(size_t width, size_t height)
	: _width(width)
	, _height(height)
	, _graph(_width, _height)
{
	assert(_width % 2 == 0);
	assert(_height % 2 == 0);
	_graph.initializeHamiltonian();

	this->_apple = this->randomPos();
	this->_snek.push_back(this->randomPos());
}

Snake::~Snake()
{ }

void Snake::draw(olc::PixelGameEngine* const pge)
{
	olc::vi2d horz(Snake::CellSizeHalf,                   0);
	olc::vi2d vert(                  0, Snake::CellSizeHalf);

	// cell background
	for(size_t col = 0; col < this->_width; ++col)
	{
		for(size_t row = 0; row < this->_height; ++row)
		{
			olc::vi2d center(col * Snake::CellSize + Snake::CellSizeHalf, row * Snake::CellSize + Snake::CellSizeHalf);
			if( (col + row) % 2 == 0)
				pge->FillRect(center -horz -vert, olc::vi2d(Snake::CellSize, Snake::CellSize), olc::Pixel(20, 20, 20));
			pge->DrawString(center -olc::vi2d{10,10}, std::to_string(row) + "," + std::to_string(col), olc::VERY_DARK_GREY, 1);
		}
	}

	for(size_t col = 0; col < this->_width; ++col)
	{
		for(size_t row = 0; row < this->_height; ++row)
		{
			const Vertex& v = this->_graph.getVertex(row, col);
			olc::vi2d center(col * Snake::CellSize + Snake::CellSizeHalf, row * Snake::CellSize + Snake::CellSizeHalf);
			if(v._north != nullptr)
				pge->DrawLine(center, center - vert, v.walkableNorth ? olc::DARK_GREEN : olc::DARK_GREY);
			if(v._south != nullptr)
				pge->DrawLine(center, center + vert, v.walkableSouth ? olc::DARK_GREEN : olc::DARK_GREY);
			if(v._east  != nullptr)
				pge->DrawLine(center, center + horz, v.walkableEast  ? olc::DARK_GREEN : olc::DARK_GREY);
			if(v._west  != nullptr)
				pge->DrawLine(center, center - horz, v.walkableWest  ? olc::DARK_GREEN : olc::DARK_GREY);
		}
	}

	// draw snek
	for(auto part : this->_snek)
	{
		olc::vi2d pos = part * Snake::CellSize;
		pge->FillRect(pos, olc::vi2d(Snake::CellSize, Snake::CellSize), olc::Pixel(0, 255, 0, 200));
	}

	// draw apple
	pge->FillCircle(this->_apple * Snake::CellSize + horz + vert, Snake::CellSizeHalf*10, olc::Pixel(255, 0, 0, 200));
}

void Snake::iterate()
{
}
