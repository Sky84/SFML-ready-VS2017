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

void GameObject::Update(float const& time)
{

}

void GameObject::Draw(sf::RenderWindow& window) const
{
	window.draw(sprite);
	/*auto hitboxDebug = sf::RectangleShape(sf::Vector2f(GetHitbox().width, GetHitbox().height));
	hitboxDebug.setFillColor(sf::Color(0,255,0,100));
	hitboxDebug.setPosition(GetHitbox().left, GetHitbox().top);
	window.draw(hitboxDebug);*/
}

sf::FloatRect GameObject::GetHitbox() const
{
	auto pos = sf::Vector2f(position.x - sprite.getGlobalBounds().width/2, position.y - sprite.getGlobalBounds().height/2);
	auto size = sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height );
	
	return sf::FloatRect(pos, size);
}

void GameObject::PositionUpdate(float const& time) {
	position += direction * (speed * time);
}

void GameObject::AnimationUpdate(float time)
{
	if (!animations.empty() && !currentAnimation.empty()) {
		auto& anim = animations.find(currentAnimation)->second;
		sprite.setTextureRect(anim.textureRects.at(currentAnimationIndex));
		anim.totalTime += time;
		if (anim.totalTime >= anim.switchTime) {
			anim.totalTime -= anim.switchTime;
			currentAnimationIndex = (currentAnimationIndex + 1) % anim.textureRects.size();
		}
	}
	UpdateSprite();
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
	auto textureRects = std::vector<sf::IntRect>{};
	for (auto i{ 0 }; i < nbrOfFrame; i++)
	{
		textureRects.push_back(sf::Rect<int>{i*spriteWidth, rowIndex*spriteHeight, spriteWidth, spriteHeight});
	}

	animations[animationName] = Animation(animationName, textureRects, switchTime);
}

void GameObject::SetTexture(sf::Texture const& p_texture)
{
	sprite.setTexture(p_texture);
	UpdateSprite();
}

void GameObject::UpdateSprite() 
{
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.x, position.y);
}

bool GameObject::checkCollision(GameObject const & other)
{
	auto futurePosition = sf::FloatRect(sf::Vector2f(GetHitbox().left, GetHitbox().top) + (direction), sf::Vector2f(GetHitbox().width, GetHitbox().height));


	if (isColliding && other.isColliding) {
		return futurePosition.intersects(other.GetHitbox());
	}
	return false;
}
