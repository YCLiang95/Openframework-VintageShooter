#include "PlayerShip.h"

void PlayerShip::keyPressed(int key) {
	switch (key) {
	case OF_KEY_UP:
	case 'w' :
		transform.acceration = 0.5f;
		break;
	case OF_KEY_DOWN:
	case 's':
		transform.acceration = -0.5f;
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
		transform.acceration = 0.0f;
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
	transform.update();
}