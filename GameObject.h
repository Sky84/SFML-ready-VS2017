#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Animation.h"
#include <map>

class GameObject {
public:
	explicit GameObject();
	explicit GameObject(std::string_view const& spritePath);
	virtual void Start();
	virtual void Update(float const& time);
	virtual void Draw(sf::RenderWindow& window) const;
	virtual sf::FloatRect GetHitbox() const;
	void AnimationUpdate(float time);
	void PositionUpdate(float const& time);
	void UpdateSprite();
	bool checkCollision(GameObject const& other);

	bool isColliding{ true };
	sf::Sprite sprite;
	sf::Vector2f position{ 0,0 };
	sf::Vector2f direction{ 0,0 };
protected:
	virtual void SetCurrentAnimation(std::string_view const& animationName);
	virtual void SetAnimation(std::string_view const& animationName, float switchTime, int rowIndex, int nbrOfFrame, int spriteWidth, int spriteHeight);
	virtual void SetTexture(sf::Texture const& p_texture);
	std::map<std::string_view, Animation> animations;
	std::string currentAnimation;
	int currentAnimationIndex;

	float speed;
private:
};