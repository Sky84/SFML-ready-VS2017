#include "InputManager.h"
#include <SFML/Graphics.hpp>

bool InputManager::Up{ false };
bool InputManager::Down{ false };
bool InputManager::Left{ false };
bool InputManager::Right{ false };

void InputManager::UpdateInput()
{
	InputManager::Up = sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	InputManager::Down = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	InputManager::Left = sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	InputManager::Right = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}
