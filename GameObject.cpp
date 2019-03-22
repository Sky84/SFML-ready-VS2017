#include "GameObject.h"

GameObject::GameObject()
{
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
	auto pos = sf::Vector2f(position.x - sprite.getGlobalBounds().width / 2, position.y - sprite.getGlobalBounds().height / 2);
	auto size = sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

	return sf::FloatRect(pos, size);
}

void GameObject::TriggerCollision(GameObject const& other) {
	if (isOnGround) {
		velocity.y = 0;
	}
	else {
		velocity = sf::Vector2f(0, 0);
	}
}

void GameObject::GravityUpdate(float const& time, float const& gravityFactor)
{
	if (useGravity && !isOnGround)
		velocity.y += gravityFactor;

	position += velocity * (speed * time);
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
	auto _textureRects = std::vector<sf::IntRect>{};
	for (auto i{ 0 }; i < nbrOfFrame; i++)
	{
		_textureRects.push_back(sf::IntRect{ i*spriteWidth, rowIndex*spriteHeight, spriteWidth, spriteHeight });
	}

	animations[animationName] = Animation(animationName, _textureRects, switchTime);
}

void GameObject::SetTexture(sf::Texture const& p_texture)
{
	sprite.setTexture(p_texture);
	UpdateSprite();
}

void GameObject::OnCollision(GameObject const& other)
{
}

void GameObject::OnTrigger(GameObject const& other)
{
}

void GameObject::UpdateSprite()
{
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.x, position.y);
}

bool GameObject::CheckCollision(GameObject const & other)
{
	auto futurePosition = sf::FloatRect(sf::Vector2f(GetHitbox().left, GetHitbox().top) + (velocity), sf::Vector2f(GetHitbox().width, GetHitbox().height));

	auto intersect = bool{ futurePosition.intersects(other.GetHitbox()) };
	isOnGround = false;
	if (intersect) {

		isOnGround = (GetHitbox().top + GetHitbox().height) - other.GetHitbox().top < 0.5f;
		if (isColliding && other.isColliding) {
			OnCollision(other);
		}
		else if (isTrigger) {
			OnTrigger(other);
		}
		return true;
	}
	return false;
}

bool GameObject::GetIsColliding()
{
	return isColliding;
}

bool GameObject::GetIsTrigger()
{
	return isTrigger;
}

void GameObject::setIsTrigger(bool const & value)
{
	isTrigger = value;
	if (isTrigger)
		isColliding = false;
}

void GameObject::setIsColliding(bool const & value)
{
	isColliding = value;
	if (isColliding)
		isTrigger = false;
}
