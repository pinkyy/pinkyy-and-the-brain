#pragma once
#include "Vector2D.h"
#include "Coder.h"


class WorldEntity
{
	private:
		double2 pos;
	public:
		virtual ~WorldEntity(void);
		virtual void encode(Coder & coder);
		virtual void decode(Coder & coder);
		virtual void draw(SDL_Surface * screen);
};
