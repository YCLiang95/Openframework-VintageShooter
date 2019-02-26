#pragma once
#include "Sprite.h"
#include "Partical.h"
#include "GameObject.h"
#include "ofMain.h"

class ParticalEmitter: public GameObject {
public:
	Sprite sprite;

	float lifeSpan;
	glm::vec3 direction;
	float speed;

	float interval;
	float timeLastSpawn;

	ofSoundPlayer emmitionSound;
	bool active = false;

	vector<Partical*> particals;

	virtual void update() override;
	virtual void draw() override;
	void spawn();
};