#pragma once
#include "ofMain.h"

class Transform {
public:
	glm::vec3 position;
	float angle;
	Transform* parent;

	float turningSpeed = 0.0f;

	float speed = 0.0f;
	float acceration = 0.0f;
	float maxSpeed = 1.0f;
	glm::vec3 direction = glm::vec3(0, -1, 0);

	glm::vec3 getPosition();
	float getAngle();

	void update();
};