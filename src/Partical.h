#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Partical : public GameObject{
public:


	virtual void update() override;
	virtual void draw() override;

	Sprite sprite;

	float lifeSpan;
	glm::vec3 direction;
	float speed;
	float timeOfSpawn;
	bool isDead = false;
};