#include "Bullet.h"
#include "ofApp.h"

void Bullet::update() {
	Particle::update();
	for (vector<GameObject*>::iterator it = ofApp::game->gameObjects.begin(); it != ofApp::game->gameObjects.end(); ++it) {
	}
}