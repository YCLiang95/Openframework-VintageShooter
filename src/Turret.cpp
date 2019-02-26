#include "Turret.h"
#include "Transform.h"
#include "GameObject.h"

void Turret::mouseMoved(int x, int y) {
	float dx = x - transform.getPosition().x;
	float dy = y - transform.getPosition().y;
	transform.angle = - atan2(dx, dy) + PI;
}

void Turret::keyPressed(int key) {
	switch (key) {
	case ' ':
  		gun.active = true;
		break;
	default:
		break;
	}
}

void Turret::keyReleased(int key) {
	switch (key) {
	case ' ':
		gun.active = false;
		break;
	default:
		break;
	}
}

void Turret::draw() {
	ofPushMatrix();
		ofTranslate(transform.getPosition());
		ofRotate(transform.angle * 180 / PI);
		ofPushMatrix();
			ofTranslate(-sprite.image.getWidth() / 2, -sprite.image.getHeight() / 2);
			sprite.image.draw(0, 0);
		ofPopMatrix();
	ofPopMatrix();
	gun.draw();
}

Turret::Turret() {
	gun = ParticalEmitter();
	gun.transform.parent = &transform;
	transform.indenpendentRotation = true;
	gun.emmitionSound.load("test_sound.wav");
	gun.emmitionSound.setVolume(0.2f);
	gun.sprite.load("bullet.png");
	gun.interval = 1000.0f;
	gun.lifeSpan = 3000.0f;
	gun.speed = 20.0f;
}

void Turret::update() {
	gun.update();
}