#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(std::string_view const & spritePath)
{
	SetTexture(Resources<sf::Texture>::getRessources(spritePath));
}

void GameObject::Start()
{
}

void GameObject::Update(float time)
{
}

void GameObject::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}

void GameObject::SetTexture(sf::Texture const& p_texture)
{
	sprite.setTexture(p_texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.x, position.y);
}
