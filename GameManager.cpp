#include "GameManager.h"
#include "InputManager.h"
const char *GameManager::WINDOW_TITLE{ "Game Engine" };

void GameManager::Start()
{
	isStarted = true;
	AddGameobject(std::make_unique<Player>());
	AddGameobject(std::make_unique<Wall>());
}

// Update is before the Draw
void GameManager::Update()
{
	auto time = chrono.restart().asSeconds();
	InputManager::UpdateInput();
	for (auto i{ 0u }; i < gameObjects.size(); i++) {
		gameObjects[i]->Update(time);
		gameObjects[i]->AnimationUpdate(time);
		for (auto j{ 0u }; j < gameObjects.size(); j++)
		{
			if (i != j && !gameObjects[i]->checkCollision(*gameObjects[j])) {
				gameObjects[i]->PositionUpdate(time);
			}
		}
	}
}

void GameManager::Draw(sf::RenderWindow& window)
{
	for (auto& gameObject : gameObjects) {
		gameObject->Draw(window);
	}
}

void GameManager::AddGameobject(std::unique_ptr<GameObject> gameObject)
{
	gameObjects.push_back(std::move(gameObject));
	gameObjects.back()->Start();
}
