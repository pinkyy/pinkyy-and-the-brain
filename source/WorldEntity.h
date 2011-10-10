#pragma once

class WorldEntity
{
	private:
		double2 pos;
	public:
		virtual ~WorldEntity(void);
		virtual encode(Coder* coder);
		virtual decode(Coder* coder);
		virtual void draw(SDL_Surface * screen);
};
