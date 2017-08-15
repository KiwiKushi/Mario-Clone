#ifndef PLAYER_H
#define PLAYER_H
#include "World.h"

class Player {
public:
	std::string name;
	sf::RenderWindow * gameWindow;
	sf::View * playerView;
	sf::RectangleShape * playerBody;
	World * currentWorld;
	float xSpeed = 10;

	Player(sf::RectangleShape * playerBody, sf::RenderWindow * gameWindow, World * currentWorld);
	bool handlePositionChange(sf::Vector2f newPos);
	void moveX(float x);
	~Player();



};


#endif // !PLAYER_H
