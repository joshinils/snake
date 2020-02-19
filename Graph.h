#pragma once

#include "Vertex.h"
#include <vector>

class Graph
{
private:
	size_t _width;
	size_t _height;
	std::vector<std::vector<Vertex>> _vertices;

public:
	Graph(size_t width, size_t height);
	~Graph();

	void initializeHamiltonian();
	const Vertex& getVertex(size_t row, size_t col);
};

