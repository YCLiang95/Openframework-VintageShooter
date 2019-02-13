#pragma once

#include "ofMain.h"

class GameObject {

public:

	glm::vec3 position;
	glm::vec3 rotation;

	vector<glm::vec3> verts;

	void collision(glm::vec3);
	void draw();
	GameObject();

};