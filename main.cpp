#include <SFML/Graphics.hpp>
#include "GameManager.h"

int main()
{
	auto gameManager = GameManager{};
	sf::RenderWindow window(sf::VideoMode(GameManager::WINDOW_WIDTH, GameManager::WINDOW_HEIGHT), GameManager::WINDOW_TITLE);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(!gameManager.isStarted)
				gameManager.Start();
		}

		gameManager.Update();

		window.clear();
		gameManager.Draw(window);
		window.display();
	}

	return 0;
}