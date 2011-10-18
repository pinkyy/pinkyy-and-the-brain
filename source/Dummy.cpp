#include <iostream>
#include "Dummy.h"


Dummy::Dummy() {	

}

Dummy::~Dummy() {
	std::cout << "iDied\n";
}

void Dummy::draw(SDL_Surface* screen) {
	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = 100;
	r.h = 50;
	
	SDL_FillRect(screen, &r, 0xFFFF00);
}
