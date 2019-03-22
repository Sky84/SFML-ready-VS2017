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
	window.draw(sprite);
}

void GameObject::AnimationUpdate(float time)
{
	if (!animations.empty() && !currentAnimation.empty()) {
		auto& anim = animations.find(currentAnimation)->second;
		sprite.setTextureRect(anim.textureRects.at(currentAnimationIndex));
		sprite.setPosition(position.x, position.y);
		sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		anim.totalTime += time;
		if (anim.totalTime >= anim.switchTime) {
			anim.totalTime -= anim.switchTime;
			currentAnimationIndex = (currentAnimationIndex + 1) % anim.textureRects.size();
		}
	}
}

void GameObject::SetCurrentAnimation(std::string_view const & animationName)
{
	auto iter = animations.find(animationName.data());
	if (iter != animations.end() && animationName != currentAnimation) {
		currentAnimation = animationName;
		currentAnimationIndex = 0;
	}
}

void GameObject::SetAnimation(std::string_view const& animationName, float switchTime, int rowIndex, int nbrOfFrame, int spriteWidth, int spriteHeight)
{
	auto textureRects = std::vector<sf::Rect<int>>{};
	for (auto i{ 0 }; i < nbrOfFrame; i++)
	{
		textureRects.push_back(sf::Rect<int>{i*spriteWidth, rowIndex*spriteHeight, spriteWidth, spriteHeight});
	}

	animations[animationName] = Animation(animationName, textureRects, switchTime);
}

void GameObject::SetTexture(sf::Texture const& p_texture)
{
	sprite.setTexture(p_texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.x, position.y);
}
