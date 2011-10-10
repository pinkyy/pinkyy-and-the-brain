#include "dummy.h"

Dummy::Dummy(int cupSize)
{
	this->cupSize;
}

Dummy::~Dummy(void)
{
	cout << "iDied\n";
}

Dummy::draw(SDL_Surface* screen)
{
	cout << "These tits are " << cupSize << " sized.\n";
}
