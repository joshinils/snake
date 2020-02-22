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
	this->Clear(olc::BLACK);

	if(!this->_snake.iterate())
	{
		system("pause");
	}
	this->_snake.draw(this);
//	system("pause");

	return true;
}
