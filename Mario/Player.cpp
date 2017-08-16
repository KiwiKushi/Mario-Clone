#include "Player.h"

Player::Player(sf::RectangleShape * playerBody, sf::RenderWindow * gameWindow, World * currentWorld, sf::Vector2f spawnPoint) {
	this->playerBody = playerBody;
	this->gameWindow = gameWindow;
	this->currentWorld = currentWorld;
	this->spawnPoint = spawnPoint;
}

bool Player::handlePositionChange(sf::Vector2f newPos) {
	for (int currentObstacleId = 0; currentObstacleId != (*this->currentWorld).obstacles.size(); currentObstacleId++) {
		sf::RectangleShape playerBodyCheck = (*this->playerBody);
		playerBodyCheck.setPosition(newPos);
		if ((*(*this->currentWorld).obstacles.at(currentObstacleId)).getGlobalBounds().intersects(playerBodyCheck.getGlobalBounds())) {
			return false;
		}
	}
	return true;
}

void Player::useGravity() {
	this->moveY((*this->currentWorld).gravity);
}

void Player::moveX(float x) {
	if (handlePositionChange(sf::Vector2f((*this->playerBody).getPosition().x+x, (*this->playerBody).getPosition().y))) {
		sf::Vector2f playerBodyPosition = (*this->playerBody).getPosition();
		(*this->playerBody).setPosition(playerBodyPosition.x + x, playerBodyPosition.y);
		sf::View currentView = (*this->gameWindow).getView();
		currentView.setCenter(sf::Vector2f((*this->playerBody).getPosition().x, currentView.getCenter().y));
		(*this->gameWindow).setView(currentView);
	}
}

void Player::moveY(float y) {
	if (handlePositionChange(sf::Vector2f((*this->playerBody).getPosition().x, (*this->playerBody).getPosition().y + y))) {
		sf::Vector2f playerBodyPosition = (*this->playerBody).getPosition();
		(*this->playerBody).setPosition(playerBodyPosition.x, playerBodyPosition.y + y);
		sf::View currentView = (*this->gameWindow).getView();
		currentView.setCenter(sf::Vector2f((*this->playerBody).getPosition().x, currentView.getCenter().y));
		(*this->gameWindow).setView(currentView);
	}
}

bool Player::checkForOutOfBounds() {
	// Nothing special right now :(

	if ((*this->playerBody).getPosition().y >= (*this->currentWorld).screenSize.y) {
		(*this->playerBody).setPosition(this->spawnPoint);
		return false;
	}
	return true;
}

Player::~Player() {

}