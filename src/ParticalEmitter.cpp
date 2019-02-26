#include "ParticalEmitter.h"
#include "ofMain.h"

void ParticalEmitter::update() {
	if (active) {
		if ((ofGetElapsedTimeMillis() - timeLastSpawn) > interval) {
			spawn();
		}
	}
	for (vector<Partical*>::iterator it = particals.begin(); it != particals.end();) {
		(**it).update();
		if ((**it).isDead) {
			it = particals.erase(it);
			//cout << "Partical Despawn!" << endl;
		} else {
			++it;
		}
	}
}

void ParticalEmitter::spawn() {
	//cout << "Partical Spawn!" << endl;
	timeLastSpawn = ofGetElapsedTimeMillis();
	Partical* partical = new Partical();
	partical->timeOfSpawn = ofGetElapsedTimeMillis();
	partical->lifeSpan = lifeSpan;
	partical->speed = speed;

	partical->sprite = sprite;
	emmitionSound.play();

	float angle = transform.getAngle();
	direction.x = cos(angle - PI / 2);
	direction.y = sin(angle - PI / 2);
	partical->direction = direction;

	partical->transform.position = transform.getPosition();

	particals.push_back(partical);
}

void ParticalEmitter::draw() {
	for (vector<Partical*>::iterator it = particals.begin(); it != particals.end(); ++it) 
		if (!(**it).isDead) (**it).draw();
}