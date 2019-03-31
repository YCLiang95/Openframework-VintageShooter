#include "ParticleSystem.h"

void ParticleSystem::update(){
	for (vector<ParticleEmitter*>::iterator it = emitters.begin(); it != emitters.end(); ++it) {
		(**it).update();
	}
};

void ParticleSystem::draw() {
	for (vector<ParticleEmitter*>::iterator it = emitters.begin(); it != emitters.end(); ++it) {
		(**it).draw();
	}
};

void ParticleSystem::addEmitter(glm::vec3 pos) {
}

void ParticleSystem::addEmitter(ParticleEmitter* emitter) {
	emitters.push_back(emitter);
}