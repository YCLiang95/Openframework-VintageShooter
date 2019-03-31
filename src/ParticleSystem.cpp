#include "ParticleSystem.h"

void ParticleSystem::update(){
	//Update all particals
	for (vector<Pawn*>::iterator it = particles.begin(); it != particles.end();) {
		(**it).update();
		//Removed dead particals
		if ((**it).isDead) {
			it = particles.erase(it);
			//cout << "Partical Despawn!" << endl;
		}
		else {
			++it;
		}
	}
};

void ParticleSystem::draw() {
	//draw all particle
	for (vector<Pawn*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		if (!(**it).isDead) (**it).draw();
	}
};

void ParticleSystem::addParticle(Pawn* particle) {
	particles.push_back(particle);
}

void ParticleSystem::applyForce(Force force) {
}
