#include "Turret.h"

void Turret::mouseMoved(int x, int y) {
	float dx = x - transform.position.x;
	float dy = y - transform.position.y;
	transform.angle = - atan2(dx, dy) + PI;
}