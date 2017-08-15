#include "Player.h"

Player::Player(sf::RectangleShape * playerBody, sf::RenderWindow * gameWindow, World * currentWorld) {
	this->playerBody = playerBody;
	this->gameWindow = gameWindow;
	this->currentWorld = currentWorld;
}

bool Player::handlePositionChange(sf::Vector2f newPos) {
	for (int currentObstacleId = 0; currentObstacleId != (*this->currentWorld).obstacles.size(); currentObstacleId++) {
		if (1 == 0) return false; // Fix this shit
	}
	return true;
}

void Player::moveX(float x) {
	if (handlePositionChange(sf::Vector2f((*this->playerBody).getPosition().x+x, (*this->playerBody).getPosition().x))) {
		sf::Vector2f playerBodyPosition = (*this->playerBody).getPosition();
		(*this->playerBody).setPosition(playerBodyPosition.x + x, playerBodyPosition.y);
		sf::View currentView = (*this->gameWindow).getView();
		currentView.setCenter(sf::Vector2f((*this->playerBody).getPosition().x, currentView.getCenter().y));
		(*this->gameWindow).setView(currentView);
	}
}

Player::~Player() {

}