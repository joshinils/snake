#include "Snake.h"
#include <cassert>
#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include <stdlib.h>

olc::vi2d Snake::randomPos()
{
	static double foo = this->_width / (double)RAND_MAX;
	static double bar = this->_height / (double)RAND_MAX;

	return olc::vi2d( int32_t(std::rand() * foo), int32_t(std::rand() * bar));
}

Snake::Snake(size_t width, size_t height)
	: _width(width)
	, _height(height)
	, _graph(_width, _height)
	, _snek()
	, _apple(this->randomPos())
{
	assert(_width % 2 == 0);
	assert(_height % 2 == 0);
	_graph.initializeHamiltonian();

	// set apple
	this->_graph.getVertex(this->_apple.x, this->_apple.y).hasApple = true;

	// place head
	Vertex& headVert = this->_graph.getVertex(this->randomPos());
	Limb head(&headVert);
	this->_snek.moveTo(head);
}

Snake::~Snake()
{ }

void Snake::draw(olc::PixelGameEngine* const pge)
{
	pge->SetPixelMode(olc::Pixel::NORMAL);

	olc::vi2d horz(Snake::cellSizeHalf,                   0);
	olc::vi2d vert(                  0, Snake::cellSizeHalf);

	// cell background, checkerboard, indices
	for(size_t col = 0; col < this->_width; ++col)
	{
		for(size_t row = 0; row < this->_height; ++row)
		{
			olc::vi2d center(int32_t(col * Snake::cellSize + Snake::cellSizeHalf), int32_t(row * Snake::cellSize + Snake::cellSizeHalf));
			if( (col + row) % 2 == 0)
				pge->FillRect(center -horz -vert, olc::vi2d(Snake::cellSize, Snake::cellSize), olc::Pixel(20, 20, 20));
			pge->DrawString(center -olc::vi2d{10,10}, std::to_string(row) + "," + std::to_string(col), olc::VERY_DARK_GREY, 1);
		}
	}

	for(size_t col = 0; col < this->_width; ++col)
	{
		for(size_t row = 0; row < this->_height; ++row)
		{
			const Vertex& v = this->_graph.getVertex(row, col);
			olc::vi2d center(int32_t(col * Snake::cellSize + Snake::cellSizeHalf), int32_t(row * Snake::cellSize + Snake::cellSizeHalf));
			const olc::Pixel& enabledColor  = olc::BLUE;
			const olc::Pixel& disabledColor = olc::DARK_GREY;
			if(v.north != nullptr)
				pge->DrawLine(center, center - vert, v.walkableNorth ? enabledColor : disabledColor);
			if(v.south != nullptr)
				pge->DrawLine(center, center + vert, v.walkableSouth ? enabledColor : disabledColor);
			if(v.east  != nullptr)
				pge->DrawLine(center, center + horz, v.walkableEast  ? enabledColor : disabledColor);
			if(v.west  != nullptr)
				pge->DrawLine(center, center - horz, v.walkableWest  ? enabledColor : disabledColor);
		}
	}

	pge->SetPixelMode(olc::Pixel::ALPHA);

	// draw snek
	for(Limb limb : this->_snek)
	{
		olc::vi2d pos = limb.getPos() * Snake::cellSize;
		std::cout << "limbpos: (" << limb.getPos().x << ", " << limb.getPos().y << ")" << std::endl;
		pge->FillRect(pos, olc::vi2d(Snake::cellSize, Snake::cellSize), olc::Pixel(0, 255, 0, Snake::opacity));

		Vertex* lv = limb.getVert();
		pge->FillCircle(lv->pos * Snake::cellSize + horz + vert, 8, olc::Pixel(255, 255, 255, Snake::opacity));
		if(lv->north != nullptr)
			pge->FillCircle(lv->north->pos * Snake::cellSize + horz + vert, 8, olc::Pixel(255,   0,   0, Snake::opacity));
		if(lv->east != nullptr)
			pge->FillCircle(lv->east ->pos * Snake::cellSize + horz + vert, 8, olc::Pixel(  0, 255,   0, Snake::opacity));
		if(lv->south != nullptr)
			pge->FillCircle(lv->south->pos * Snake::cellSize + horz + vert, 8, olc::Pixel(  0,   0, 255, Snake::opacity));
		if(lv->west != nullptr)
			pge->FillCircle(lv->west ->pos * Snake::cellSize + horz + vert, 8, olc::Pixel(255,   0, 255, Snake::opacity));
	}

	// draw apple
	pge->FillCircle(this->_apple * Snake::cellSize + horz + vert, int32_t(Snake::cellSizeHalf*0.8), olc::Pixel(255, 0, 0, Snake::opacity));
}

bool Snake::iterate()
{
	Limb& head = this->_snek.getHead();
	Vertex* headVert = head.getVert();
	Limb nextPos;

	if(headVert->walkableNorth && !headVert->north->hasLimb)
		nextPos.setVert(headVert->north);
	else if(headVert->walkableEast && !headVert->east->hasLimb)
		nextPos.setVert(headVert->east);
	else if(headVert->walkableSouth && !headVert->south->hasLimb)
		nextPos.setVert(headVert->south);
	else if(headVert->walkableWest && !headVert->west->hasLimb)
		nextPos.setVert(headVert->west);
	else
		return false; // cant make a move along the path

	this->_snek.moveTo(nextPos);
	return true;
}
