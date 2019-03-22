#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(std::string_view const & p_animationName, std::vector<sf::Rect<int>> const& p_textureRects,float p_switchTime) : name{p_animationName}, textureRects{p_textureRects}, switchTime{p_switchTime}
{
}
