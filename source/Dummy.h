#pragma once
#include "WorldEntity.h"


class Dummy : public WorldEntity
{
	private:
		double2 v;
		

	public:
		Dummy();
		~Dummy();
		void draw(SDL_Surface* screen);
		void advance(double dt);
};
