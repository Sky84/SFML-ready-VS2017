#include "Wall.h"
#include "Resources.h"

Wall::Wall()
{
	SetTexture(Resources<sf::Texture>::getRessources("resources/wall.jpg"));
}

void Wall::Start()
{
	position = sf::Vector2f(300, 300);
}
