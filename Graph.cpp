#include "Graph.h"
#include <vector>
#include <iostream>
#include "Vertex.h"
#include <cassert>

Graph::Graph(size_t width, size_t height)
	: _width(width)
	, _height(height)
	, _vertices(_height, std::vector<Vertex>(_width))
{
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
}

const Vertex & Graph::getVertex(size_t row, size_t col)
{
	assert(row < this->_vertices.size());
	assert(col < this->_vertices[0].size());
	return this->_vertices[row][col];
}
