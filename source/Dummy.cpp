#include <iostream>
#include "Dummy.h"
#include <math.h>


Dummy::Dummy() {	
	pos.x = 5.0;
	pos.y = 20.0;
	v.x = 50;
}

Dummy::~Dummy() {
	std::cout << "iDied\n";
}

void Dummy::advance(double dt)
{
	pos.x += v.x * dt;
	pos.y = 20.0 - 10.0 * sin(pos.x);
}

void Dummy::draw(SDL_Surface* screen) {
	SDL_Rect r;
	r.x = pos.x;
	r.y = pos.y;
	r.w = 10.0 + 5.0 * sin(pos.x + 1.0);
	r.h = 10.0 + 5.0 * cos(pos.x + 1.0);
	
	SDL_FillRect(screen, &r, 0xFFFF00);
}
