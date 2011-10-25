#pragma once
#include "WorldEntity.h"


class DummyCounter : public WorldEntity
{
private:
	SDL_Surface * bitmap;
	
public:
	DummyCounter() {
		bitmap = SDL_LoadBMP("./data/counter.bmp");
	}
	void draw(SDL_Surface* screen) {
		SDL_Rect src;
		src.x = 0;
		src.y = 0;
		src.w = 32;
		src.h = 48;
		
		SDL_Rect dst;
		dst.x = 0;
		dst.y = 500;
		dst.w = 32;
		dst.h = 48;
		
		for (int i = 0; i < 800; i += dst.w) {
			dst.x = i;
			SDL_BlitSurface(bitmap, &src, screen, &dst);
		}
	}
};
