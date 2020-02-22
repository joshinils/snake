#include "Graph.h"
#include <vector>
#include <iostream>
#include "Vertex.h"
#include <cassert>
#include "olcPixelGameEngine/olcPixelGameEngine.h"

Graph::Graph(size_t width, size_t height)
	: _width(width)
	, _height(height)
	, _vertices(_height, std::vector<Vertex>(_width))
{
	// set positions
	for(size_t row = 0; row < this->_height; ++row)
	{
		for(size_t col = 0; col < this->_width; ++col)
		{
			this->_vertices[row][col].pos = olc::vi2d(col, row); // i dont understand why the pos is swapped in its arguments
		}
	}

	// connect for later traversal
	for(size_t row = 1; row < this->_height; ++row)
	{
		for(size_t col = 0; col < this->_width; ++col)
		{
			this->_vertices[row][col].connectNorth(&_vertices[row-1][col  ]);
		}
	}

	for(size_t row = 0; row < this->_height; ++row)
	{
		for(size_t col = 1; col < this->_width; ++col)
		{
			this->_vertices[row][col-1].connectEast(&_vertices[row  ][col]);
		}
	}
}

Graph::~Graph()
{
}

void Graph::initializeHamiltonian()
{
	Vertex* v = &this->_vertices[0][0];
	while(v != nullptr)
	{
		v->unblockEast();
		v = v->east;
	}

	v = &this->_vertices[0][0];
	while(v != nullptr)
	{
		v->unblockSouth();
		v = v->south;
	}

	v = &this->_vertices[this->_height-1][0];
	while(v != nullptr)
	{
		v->unblockEast();
		v = v->east;
	}

	for(size_t row = 1; row < this->_height; ++row)
	{
		for(size_t col = 1; col < this->_width; ++col)
		{
			this->_vertices[row][col].unblockEast();
		}
	}

	for(size_t row = 0; row < this->_height; ++row)
	{
		if(row % 2 == 1)
			this->_vertices[row][1].unblockSouth();
		else
			this->_vertices[row][this->_width-1].unblockSouth();
	}
}

Vertex* Graph::getVertex(size_t row, size_t col)
{
	assert(row < this->_vertices.size());
	assert(col < this->_vertices[0].size());
	return &this->_vertices[row][col];
}

Vertex* Graph::getVertex(const olc::vi2d& pos)
{
	return this->getVertex(pos.y, pos.x);
}
