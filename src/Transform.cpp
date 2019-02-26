#include "Transform.h"

glm::vec3 Transform::getPosition() { 
	if (parent != NULL)
		return parent->getPosition() + position; 
	else 
		return position; 
};

float Transform::getAngle() {
	if (!indenpendentRotation && parent != NULL)
		return parent->getAngle() + angle;
	else
		return angle;
};

void Transform::update() {
	if (turningSpeed != 0.0f) {
		angle += turningSpeed;
		direction.x = cos(angle - PI / 2);
		direction.y = sin(angle - PI / 2);
	}
	if (acceration != 0) {
		speed += acceration;
		if (speed > 0.0f)
			speed = min(speed, maxSpeed);
		else
			speed = max(speed, -maxSpeed);
	} else {
		speed *= (1.0f - drag);
		if (abs(speed) < 0.05f) speed = 0.0f;
	}
	if (abs(speed) > 0.0f) {
		position += direction * speed;
	}
}