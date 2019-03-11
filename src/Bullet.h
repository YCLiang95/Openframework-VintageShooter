#pragma once
#include "particle.h"

class Bullet:public Particle {
public:
	int damage;

	void update() override;
};