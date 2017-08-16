#include "World.h"

World::World(sf::RectangleShape * background, std::string worldName, sf::Vector2i screenSize, float gravity) {
	this->background = background;
	this->worldName = worldName;
	this->screenSize = screenSize;
	this->gravity = gravity;


}

World::~World() {

}