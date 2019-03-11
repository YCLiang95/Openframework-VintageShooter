#include "Particle.h"

void Particle::update() {
	if (ofGetElapsedTimeMillis() - timeOfSpawn > lifeSpan) isDead = true;
	transform.speed = speed;
	transform.direction = direction;
	transform.update();
}

void Particle::draw() {
	ofPushMatrix();
		ofTranslate(transform.getPosition());
		ofRotate(transform.getAngle() * 180 / PI);
		ofPushMatrix();
			ofTranslate(-sprite.image.getWidth() / 2, -sprite.image.getHeight() / 2);
			sprite.image.draw(0, 0);
		ofPopMatrix();
	ofPopMatrix();
}