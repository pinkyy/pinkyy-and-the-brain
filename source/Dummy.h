#pragma once

class Dummy : public WorldEntity
{
	private:
		int cupSize;
	public:
		Dummy(int cupSize);
		~Dummy(SDL_Surface* screen);
		void draw();
};
