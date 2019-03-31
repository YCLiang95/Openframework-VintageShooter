#include "PlayerShip.h"

void PlayerShip::keyPressed(int key) {
	switch (key) {
	case OF_KEY_UP:
	case 'w' :
		accerating = 1;
		break;
	case OF_KEY_DOWN:
	case 's':
		accerating = -1;
		break;
	case OF_KEY_RIGHT:
	case 'd':
		transform.turningSpeed = 0.05f;
		break;
	case OF_KEY_LEFT:
	case 'a':
		transform.turningSpeed = -0.05f;
		break;
	default:
		break;
	}
}

void PlayerShip::keyReleased(int key) {
	switch (key) {
	case OF_KEY_UP:
	case 'w':
	case OF_KEY_DOWN:
	case 's':
		accerating = 0;
		break;
	case OF_KEY_RIGHT:
	case 'd':
	case OF_KEY_LEFT:
	case 'a':
		transform.turningSpeed = 0.0f;
		break;
	default:
		break;
	}
}

void PlayerShip::update() {
	if (accerating != 0) {
		transform.accerationDirection = accerating * transform.direction;
		transform.acceration = 1.0f;
		AnimatedSprite* p = (AnimatedSprite*)sprite;
		p->play = true;
		p->update();
	}
	transform.update();
}