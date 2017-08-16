#ifndef PLAYER_H
#define PLAYER_H
#include "World.h"

class Player {
public:
	std::string name;
	sf::RenderWindow * gameWindow;
	sf::View * playerView;
	sf::RectangleShape * playerBody;
	sf::Vector2f spawnPoint;
	World * currentWorld;
	float xSpeed = 10;
	float ySpeed = 10;

	Player(sf::RectangleShape * playerBody, sf::RenderWindow * gameWindow, World * currentWorld, sf::Vector2f spawnPoint);
	bool handlePositionChange(sf::Vector2f newPos);
	void useGravity();
	void moveX(float x);
	void moveY(float y);
	bool checkForOutOfBounds();
	~Player();



};


#endif // !PLAYER_H
