#pragma once
#include "Player.h"
#include "Wall.h"

class GameManager {
public:
	void Start();
	void Update();
	void Draw(sf::RenderWindow& window);
	void AddGameobject(std::unique_ptr<GameObject> gameObject);
	bool isStarted{ false };

	static const char *WINDOW_TITLE;
	static const int WINDOW_WIDTH{ 800 };
	static const int WINDOW_HEIGHT{ 600 };

private:
	std::vector<std::unique_ptr<GameObject>> gameObjects{};
	sf::Clock chrono;
};