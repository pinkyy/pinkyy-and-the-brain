#include <iostream>
#include <SDL/SDL.h>
using namespace std;

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(800, 600, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	SDL_Event event;
	bool keepRunning=true;
	
	while (keepRunning) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				keepRunning = false;
		}
	}
	return 0;
}

