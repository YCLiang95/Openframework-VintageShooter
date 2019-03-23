#pragma once
#include "ParticleEmitter.h"
//Not Implemented yet
//A Partical system will controll mutilple emitter

class ParticleSystem {
public:
	vector<ParticleEmitter*> emitters;

	void update();

	void addEmitter(glm::vec3 pos);
	void addEmitter(ParticleEmitter* emitter);

	void draw();
};