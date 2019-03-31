#include "Particle.h"

void Particle::update() {
	if (ofGetElapsedTimeMillis() - timeOfSpawn > lifeSpan) isDead = true;
	transform.update();
}

void Particle::draw() {
	sprite->draw(transform);
}

Pawn* Particle::clone() {
	Particle* result = new Particle(*this);
	result->timeOfSpawn = ofGetElapsedTimeMillis();
	return result;
};