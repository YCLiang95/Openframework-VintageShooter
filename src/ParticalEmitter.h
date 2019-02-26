#pragma once
#include "Sprite.h"
#include "GameObject.h"

class ParticalEmitter: GameObject {
public:
	Sprite sprite;

	float lifeSpan;
	glm::vec3 direction;
	float speed;

	float interval;
	float lastSpawn;
};