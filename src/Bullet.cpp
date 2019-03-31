#include "Bullet.h"
#include "ofApp.h"

void Bullet::update() {
	Particle::update();
	trail.addVertex(transform.position);
	if (trail.size() > 10){
		trail.getVertices().erase(trail.getVertices().begin());
		trail.flagHasChanged();
	}
}

void Bullet::draw() {
	sprite->draw(transform);
	//trials->draw(firedPosition);
	ofSetColor(156, 80, 0, 100);
	trail.draw();
	ofSetColor(255, 255, 255);
}

Pawn* Bullet::clone() {
	Bullet* result = new Bullet(*this);
	result->timeOfSpawn = ofGetElapsedTimeMillis();
	result->firedPosition = transform.position;
	result->trail.addVertex(transform.position);
	return result;
}