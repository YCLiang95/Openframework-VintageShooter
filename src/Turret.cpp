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

//Most part are the same as it's parent pawn
void Turret::draw() {
	ofPushMatrix();
		ofTranslate(transform.getPosition());
		//Becase turrent roate follows mouse
		//It should not inherate parent's rotation
		ofRotate(transform.angle * 180 / PI);
		ofPushMatrix();
			ofTranslate(-sprite.image.getWidth() / 2, -sprite.image.getHeight() / 2);
			sprite.image.draw(0, 0);
		ofPopMatrix();
	ofPopMatrix();
	gun.draw();
}

//Constructor
//Temporary put the emitter set up code here
//They will be moved to the partical system once finished
Turret::Turret() {
	gun = ParticleEmitter();
	gun.transform.parent = &transform;
	transform.indenpendentRotation = true;
	gun.emmitionSound.load("test_sound.wav");
	gun.emmitionSound.setVolume(0.1f);
	//gun.sprite.load("bullet.png");
	Bullet bullet = Bullet();
	bullet.lifeSpan = 3000.0f;
	bullet.sprite.load("bullet.png");
	bullet.transform.drag = 0.0f;
	gun.particle = bullet;
	//bullet.transform.s
	gun.interval = 1000.0f;
	//gun.lifeSpan = 3000.0f;
	gun.speed = 20.0f;
}

void Turret::update() {
	gun.update();
	//I need to fix this once I have time
	for (vector<Pawn*>::iterator itb = gun.particles.begin(); itb != gun.particles.end(); ++itb) {
		for (vector<ParticleSystem*>::iterator it = ofApp::game->particleSystems.begin(); it != ofApp::game->particleSystems.end(); ++it)
			for (vector<ParticleEmitter*>::iterator it2 = (**it).emitters.begin(); it2 != (**it).emitters.end(); ++it2)
				for (vector<Pawn*>::iterator it3 = (**it2).particles.begin(); it3 != (**it2).particles.end(); ++it3)
					if (Transform::collide((**itb).transform, (**it3).transform)) {
						(**it3).isDead = true;
						(**itb).isDead = true;
					}
	}
}