#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player();
	virtual void Start() override;
	virtual void Update(float time) override;

private:
	int speed{ 30 };
};

