#include "Aether.h"
#include "olcPixelGameEngine/olcPixelGameEngine.h"

Aether::Aether(size_t width, size_t height)
	: _snake(width, height)
{

}

Aether::~Aether()
{

}

bool Aether::OnUserCreate()
{
	olc::PixelGameEngine::SetPixelMode(olc::Pixel::ALPHA);
	std::cout << __FUNCTION__ << std::endl;
	return true;
}

bool Aether::OnUserUpdate(float fElapsedTime)
{
//	while(this->_snake.iterate());
//	return false;
	this->Clear(olc::BLACK);

	static int iterations = 0;


	if (true) // DO ITERATE? this is a debug thingy
	{
		if (!this->_snake.iterate())
		{
			std::cout << iterations << std::endl;
			return false;
			system("pause");
		}
		++iterations;

	}
	this->_snake.draw(this);
//	system("pause");

	return true;
}
