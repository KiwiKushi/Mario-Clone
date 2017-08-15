#include "World.h"

World::World(sf::RectangleShape * background, std::string worldName, sf::Vector2i screenSize) {
	this->background = background;
	this->worldName = worldName;
	this->screenSize = screenSize;


}

World::~World() {

}