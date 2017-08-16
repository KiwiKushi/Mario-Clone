#ifndef WORLD_H
#define WORLD_H
#include<iostream>
#include<string>
#include<vector>
#include<SFML\Graphics.hpp>

class World {
public:

	sf::RectangleShape * background;
	std::string worldName;
	std::vector<sf::RectangleShape*> obstacles;
	std::vector<sf::RectangleShape*> viewables;
	sf::Vector2i screenSize;
	float gravity;

	World(sf::RectangleShape * background, std::string worldName, sf::Vector2i screenSize, float gravity);
	~World();
};


#endif // WORLD_H