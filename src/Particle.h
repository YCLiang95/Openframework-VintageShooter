#pragma once
#include "GameObject.h"
#include "Sprite.h"

//The partical, emitted by the emitter
class Particle : public GameObject{
public:


	virtual void update() override;
	virtual void draw() override;

	//The sprite used
	Sprite sprite;

	float lifeSpan;
	glm::vec3 direction;
	float speed;
	float timeOfSpawn;
};