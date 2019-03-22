#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <string_view>

struct Animation
{
public:
	Animation();
	Animation(std::string_view const& p_animationName, std::vector<sf::IntRect> const& p_textureRects, float p_switchTime);
	std::string_view name{};
	std::vector<sf::IntRect> textureRects{};
	float switchTime{};
	float totalTime{};
};

