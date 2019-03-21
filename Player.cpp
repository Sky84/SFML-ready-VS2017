#include "Player.h"
#include "InputManager.h"
Player::Player()
{
	SetTexture(Resources<sf::Texture>::getRessources("resources/player.png"));
}

void Player::Start()
{
}

void Player::Update(float time)
{
	auto direction = sf::Vector2f(0, 0);
	if (InputManager::Up)
		direction.y = -1;
	else if(InputManager::Down)
		direction.y = 1;
	if (InputManager::Left)
		direction.x = -1;
	else if (InputManager::Right)
		direction.x = 1;

	position += sf::Vector2f((direction.x * speed)*time, (direction.y * speed)*time);

}
