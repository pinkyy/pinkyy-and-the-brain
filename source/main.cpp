#include <iostream>
#include <SDL/SDL.h>
#include "World.h"
#include "engine/net/packet.h"
#include "Dummy.h"

using namespace std;


int main(int argc, char** argv) {
	
	//Initialize the SDL video subsystem.
	SDL_Init(SDL_INIT_VIDEO);
	
	//Set the initial video mode. This will open a new window ready for drawing stuff. We have to
	//keep the SDL_Surface it returns around so we may draw stuff on it.
	SDL_Surface * screen = SDL_SetVideoMode(800, 600, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	World * world = new World;
	world->screen = screen;
	
	Dummy * dummy = new Dummy;
	world->entities.push_back(dummy);
	
	//Load the test tile.
	SDL_Surface * test = SDL_LoadBMP("./data/test.bmp");
	
	//Enter the main event loop.
	SDL_Event event;
	bool keepRunning = true;
	int previousFrame = 0;
	while (keepRunning) {
		
		//perform time measurment.
		int now, msdt;
		do {
			now = SDL_GetTicks();
			msdt = now - previousFrame;
		} while (msdt == 0);
		previousFrame = now;
		double dt = (double)msdt / 1000;
		if (dt > 0.1) dt = 0.1;
		
		//Show some debuggin information in the window title bar.
		char title[512];
		snprintf(title, 512, "Pinkyy and the Brain | %3.0fHz", 1/dt);
		SDL_WM_SetCaption(title, NULL);
		
		//Check whether there is an event in the queue that needs processing and do so.
		if (SDL_PollEvent(&event)) {
			
			//If the user wants to quit the game, set keepRunning to false so the main while loop
			//will exit.
			if (event.type == SDL_QUIT)
				keepRunning = false;
		}
		
		
		
		//Draw the test sprite.
		SDL_Rect source;
		source.x = 0;
		source.y = 0;
		source.w = 96;
		source.h = 96;
		
		SDL_Rect destination;
		destination.x = 100;
		destination.y = 100;
		destination.w = 96;
		destination.h = 96;
		
		//clear screen.
		SDL_FillRect(screen, NULL, 0);
		
		//animate and draw world.
		world->advance(dt);
		world->draw();
		
		SDL_BlitSurface(test, &source, screen, &destination);
		
		//Flip the buffers so whatever we've just drawn gets visible.
		SDL_Flip(screen);
	}
	
	//Terminate SDL
	SDL_Quit();
	return 0;
}

