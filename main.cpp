#include "Aether.h"
#include <stdlib.h>
#include "Snake.h"

int main()
{
	std::srand(0); // always same
	size_t width = 5 * 2;
	size_t height = 3 * 2;
	Aether world(width, height);
	if (world.Construct(width * Snake::CellSize, height * Snake::CellSize, 1, 1) )
	{
		world.Start();
	}
	return 0;
}
