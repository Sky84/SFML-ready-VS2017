#include "Player.h"
#include "InputManager.h"
Player::Player()
{
	SetTexture(Resources<sf::Texture>::getRessources("resources/player.png"));
}

void Player::Start()
{
	InitAnimations();
}

void Player::InitAnimations()
{
	auto switchTime = 0.1f;
	SetAnimation("up", switchTime, 0, 9, 64, 64);
	SetAnimation("left", switchTime, 1, 9, 64, 64);
	SetAnimation("down", switchTime, 2, 9, 64, 64);
	SetAnimation("right", switchTime, 3, 9, 64, 64);
	SetAnimation("idle", switchTime, 2, 1, 64, 64);

	SetCurrentAnimation("idle");
}

void Player::Update(float time)
{
	auto direction = sf::Vector2f(0, 0);
	if (InputManager::Up) {
		direction.y = -1;
		SetCurrentAnimation("up");
	}
	else if (InputManager::Down) {
		direction.y = 1;
		SetCurrentAnimation("down");
	}
	if (InputManager::Left) {
		direction.x = -1;
		SetCurrentAnimation("left");
	}
	else if (InputManager::Right) {
		direction.x = 1;
		SetCurrentAnimation("right");
	}

	if (direction == sf::Vector2f(0, 0))
		SetCurrentAnimation("idle");

	position += direction * (speed * time);

}
