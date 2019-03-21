#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class GameObject {
public:
	GameObject();
	GameObject(std::string_view const& spritePath);
	virtual void Start();
	virtual void Update(float time);
	virtual void Draw(sf::RenderWindow& window);
	virtual void SetTexture(sf::Texture const& p_texture);

	sf::Sprite sprite;
	sf::Vector2f position{ 0,0 };
};