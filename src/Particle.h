#pragma once
#include "Pawn.h"
#include "Sprite.h"

//The partical, emitted by the emitter
class Particle : public Pawn{
public:


	virtual void update() override;
	virtual void draw() override;
	virtual Pawn* clone() override;

	float lifeSpan;
	glm::vec3 direction;
	float speed;
	float timeOfSpawn;
};