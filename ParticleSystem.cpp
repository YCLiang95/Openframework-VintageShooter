#include "ParticleSystem.h"

void ParticleSystem::update(){
};

void ParticleSystem::draw() {
};

void ParticleSystem::addEmitter(glm::vec3 pos) {
}

void ParticleSystem::addEmitter(ParticleEmitter emitter) {
	emitters.push_back(emitter);
}