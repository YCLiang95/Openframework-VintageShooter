#pragma once
#include "ofMain.h"

class Transform {
public:
	glm::vec3 position;
	float angle;
	Transform* parent;

	glm::vec3 getPosition() { if (parent != NULL) return parent->getPosition() + position; else return position; };

};