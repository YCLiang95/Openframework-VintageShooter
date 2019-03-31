#include "Turret.h"
#include "Transform.h"
#include "GameObject.h"
#include "ParticleSystem.h"
#include "ofApp.h"

void Turret::mouseMoved(int x, int y) {
	float dx = x - transform.getPosition().x;
	float dy = y - transform.getPosition().y;
	transform.angle = - atan2(dx, dy) + PI;
}

void Turret::keyPressed(int key) {
	switch (key) {
	case ' ':
  		gun->active = true;
		break;
	default:
		break;
	}
}

void Turret::keyReleased(int key) {
	switch (key) {
	case ' ':
		gun->active = false;
		break;
	default:
		break;
	}
}

//Most part are the same as it's parent pawn
void Turret::draw() {
	sprite->draw(transform);
	gun->draw();
}

//Constructor
//Temporary put the emitter set up code here
//They will be moved to the partical system once finished
Turret::Turret(ParticleSystem* p) {
	Bullet* bullet = new Bullet();
	bullet->lifeSpan = 3000.0f;
	bullet->sprite = new Sprite();
	bullet->sprite->load("bulletTrail.png");
	bullet->transform.drag = 0.0f;
	bullet->transform.size = 5.0f;

	gun = new ParticleEmitter(p, bullet);
	gun->transform.parent = &transform;
	transform.indenpendentRotation = true;
	gun->emmitionSound.load("test_sound.wav");
	gun->emmitionSound.setVolume(0.1f);
	gun->particle = bullet;
	gun->interval = 1000.0f;
	gun->speed = 100.0f;
}

void Turret::update() {
	gun->update();
}