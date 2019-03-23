#pragma once
#include "particle.h"

class Bullet:public Particle {
public:
	int damage;

	virtual void update() override;
};