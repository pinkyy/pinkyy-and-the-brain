#include <iostream>
#include "World.h"


void World::draw() {
	for (int i = 0; i < entities.size(); i++)
		entities[i]->draw(screen);
}


