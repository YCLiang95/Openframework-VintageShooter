#pragma once
#include "particle.h"
#include "Sprite.h"

class Bullet:public Particle {
public:
	int damage;
	Sprite* trials;
	virtual void update() override;
	virtual void draw() override;
	virtual Pawn* clone() override;
	glm::vec3 firedPosition;
	ofPolyline trail;
};