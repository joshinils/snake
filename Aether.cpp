#include "Aether.h"
#include "olcPixelGameEngine/olcPixelGameEngine.h"

Aether::Aether()
{

}

Aether::~Aether()
{

}

bool Aether::OnUserCreate()
{
	// olc::PixelGameEngine::SetPixelMode(olc::Pixel::ALPHA);
	std::cout << __FUNCTION__ << std::endl;
	return true;
}

bool Aether::OnUserUpdate(float fElapsedTime)
{
	this->Clear(olc::BLACK);

	return true;
}
