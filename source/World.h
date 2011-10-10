#include <SDL/SDL.h>
#include <vector>
#include "WorldEntity.h"


class World {
	public:
	SDL_Surface * screen;
	std::vector<WorldEntity *> entities;
	void draw();
};
