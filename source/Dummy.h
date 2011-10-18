#pragma once
#include "WorldEntity.h"


class Dummy : public WorldEntity
{
	public:
		Dummy();
		~Dummy();
		void draw(SDL_Surface* screen);
};
