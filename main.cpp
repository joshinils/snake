#include "Aether.h"
#include <stdlib.h>

int main()
{
	srand(0); // always same
	double scale = 120;
	Aether world;
	if (world.Construct((uint32_t)(16.0*scale), (uint32_t)(9.0*scale), (uint32_t)std::max(1.0, 120 / scale), (uint32_t)std::max(1.0, 120 / scale)))
	{
		world.Start();
	}
	return 0;
}
