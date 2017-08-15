#include<iostream>
#include<string>
#include<vector>
#include<direct.h>
#include<SFML\Graphics.hpp>
#include "World.h"
#include "Player.h"


std::string getCurrentDir() {
	char * path = NULL;
	path = _getcwd(NULL, 0);
	return path;
}



int main() {
	sf::Vector2i screenSize(800, 600);
	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Mario");


	sf::Image worldOneBackgroundImage;
	worldOneBackgroundImage.loadFromFile(getCurrentDir() + "\\Assets\\Textures\\Backgrounds\\World_01_Background.png");

	sf::Texture worldOneBackgroundTexture;
	worldOneBackgroundTexture.loadFromImage(worldOneBackgroundImage);
	worldOneBackgroundTexture.setRepeated(true);

	sf::RectangleShape worldOneBackground;
	worldOneBackground.setTexture(&worldOneBackgroundTexture);
	worldOneBackground.setPosition(sf::Vector2f(0, 0));
	worldOneBackground.setSize(sf::Vector2f(screenSize.x*50, screenSize.y));
	worldOneBackground.setTextureRect(sf::IntRect(0, 0, screenSize.x*20, screenSize.y));

	World currentWorld(&worldOneBackground, "World One", screenSize);


	sf::RectangleShape box;
	box.setFillColor(sf::Color::Red);
	box.setSize(sf::Vector2f(50,50));
	box.setPosition(sf::Vector2f(1000, 300));

	currentWorld.obstacles.push_back(&box);



	sf::RectangleShape playerBody;
	playerBody.setFillColor(sf::Color::Green);
	playerBody.setPosition(sf::Vector2f(screenSize.x / 2, screenSize.y / 2));
	playerBody.setSize(sf::Vector2f(50, 50));


	Player player(&playerBody, &window, &currentWorld);

	while (window.isOpen()) {


		window.clear(sf::Color::Black);
		
		sf::Event event;
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				player.moveX(10);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				player.moveX(-10);
			}
		}


		window.draw(*currentWorld.background);

		for (int x = 0; x != currentWorld.obstacles.size(); x++) {
			window.draw(*currentWorld.obstacles.at(x));
		}

		window.draw(*player.playerBody);
		window.display();

	}
	


	return 0;
}