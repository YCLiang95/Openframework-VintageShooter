#include "Bullet.h"
#include "ofApp.h"

void Bullet::update() {
	Particle::update();
}

void Bullet::draw() {
	sprite->draw(transform);
	trials->draw(transform);
}

Pawn* Bullet::clone() {
	Bullet* result = new Bullet(*this);
	result->timeOfSpawn = ofGetElapsedTimeMillis();
	return result;
}