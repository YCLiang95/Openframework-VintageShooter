#include "ParticleEmitter.h"
#include "ofMain.h"

void ParticleEmitter::update() {
	if (active) {
		if ((ofGetElapsedTimeMillis() - timeLastSpawn) > interval) {
			spawn();
		}
	}

	//Update all particals
	for (vector<Pawn*>::iterator it = particles.begin(); it != particles.end();) {
		(**it).update();
		//Removed dead particals
		if ((**it).isDead) {
			it = particles.erase(it);
			//cout << "Partical Despawn!" << endl;
		} else {
			++it;
		}
	}
}

//Spawn a new partical
//This part will be modulized later for more flexibility
void ParticleEmitter::spawn() {
	//cout << "Partical Spawn!" << endl;
	timeLastSpawn = ofGetElapsedTimeMillis();
	//Particle* partical = new Particle();

	Pawn* partical = new Pawn(particle);

	//partical->timeOfSpawn = ofGetElapsedTimeMillis();
	//partical->lifeSpan = lifeSpan;

	partical->sprite = sprite;
	emmitionSound.play();

	float angle = transform.getAngle();
	direction.x = cos(angle - PI / 2);
	direction.y = sin(angle - PI / 2);

	partical->transform.position = transform.getPosition();
	partical->transform.speed = speed;
	partical->transform.direction = direction;

	particles.push_back(partical);
}

void ParticleEmitter::draw() {
	for (vector<Pawn*>::iterator it = particles.begin(); it != particles.end(); ++it)
		if (!(**it).isDead) (**it).draw();
}