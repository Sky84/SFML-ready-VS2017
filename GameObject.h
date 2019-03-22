#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <map>

class GameObject {
public:
	explicit GameObject();
	virtual void Start();
	virtual void Update(float const& time);
	virtual void Draw(sf::RenderWindow& window) const;
	virtual sf::FloatRect GetHitbox() const;
	void AnimationUpdate(float time);
	void TriggerCollision(GameObject const& other);
	void GravityUpdate(float const& time, float const& gravityFactor);
	void UpdateSprite();
	bool CheckCollision(GameObject const& other);

	bool GetIsColliding();
	bool GetIsTrigger();

	sf::Sprite sprite;
	sf::Vector2f position{ 0,0 };
	sf::Vector2f velocity{ 0,0 };
protected:
	virtual void SetCurrentAnimation(std::string_view const& animationName);
	virtual void SetAnimation(std::string_view const& animationName, float switchTime, int rowIndex, int nbrOfFrame, int spriteWidth, int spriteHeight);
	virtual void SetTexture(sf::Texture const& p_texture);
	virtual void OnCollision(GameObject const& other);
	virtual void OnTrigger(GameObject const& other);
	void setIsTrigger(bool const& value);
	void setIsColliding(bool const& value);

	std::map<std::string_view, Animation> animations;
	std::string currentAnimation;
	int currentAnimationIndex;

	bool useGravity{ false };
	bool isOnGround{ false };
	float speed;
private:
	bool isColliding{ true };
	bool isTrigger{ false };
};