#include "Player.h"
#include "InputManager.h"
#include "Resources.h"
Player::Player()
{
	SetTexture(Resources<sf::Texture>::getRessources("resources/player.png"));
}

void Player::Start()
{
	InitAnimations();
	speed = 30;
	position = sf::Vector2f(300, 100);
	useGravity = true;
}

void Player::InitAnimations()
{
	auto switchTime = 0.1f;
	SetAnimation("up", switchTime, 0, 9, 64, 64);
	SetAnimation("left", switchTime, 1, 9, 64, 64);
	SetAnimation("down", switchTime, 2, 9, 64, 64);
	SetAnimation("right", switchTime, 3, 9, 64, 64);
	SetAnimation("idle", switchTime, 2, 1, 64, 64);
}

void Player::Update(float const& time)
{
	velocity = sf::Vector2f(0, 0);
	if (InputManager::Up) {
		velocity.y = -1;
		SetCurrentAnimation("up");
	}
	else if (InputManager::Down) {
		velocity.y = 1;
		SetCurrentAnimation("down");
	}
	if (InputManager::Left) {
		velocity.x = -1;
		SetCurrentAnimation("left");
	}
	else if (InputManager::Right) {
		velocity.x = 1;
		SetCurrentAnimation("right");
	}

	if (velocity == sf::Vector2f(0, 0))
		SetCurrentAnimation("idle");

	GameObject::Update(time);
}
