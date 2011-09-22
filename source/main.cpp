#include <iostream>
#include <SDL/SDL.h>
using namespace std;

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(800, 600, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	while (true);
	return 0;
}


