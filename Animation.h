#pragma once
#include "SFML/Graphics.hpp"

struct Animation
{
	Animation();
	explicit Animation(std::string_view const& p_animationName, std::vector<sf::Rect<int>> const& p_textureRects, float p_switchTime);
public:
	std::string_view name{};
	std::vector<sf::Rect<int>> textureRects{};
	float switchTime{};
	float totalTime{};
};

