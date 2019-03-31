#pragma once
#include "Sprite.h"
#include "Particle.h"
#include "Pawn.h"
#include "ofMain.h"
#include "ParticleSystem.h"

class ParticleEmitter: public GameObject {
public:
	Pawn* particle;
	ParticleSystem* pSystem;

	//How long spawned partical should lived, in mil-sec
	float lifeSpan;
	//The direction of the spawn partical
	glm::vec3 direction;
	//The speed of the spawned partical
	float speed;

	//How long, in mil-sec, between partical spawn
	float interval;
	//System time since last partical spawn
	float timeLastSpawn;

	//Sound when partical spawn
	ofSoundPlayer emmitionSound;

	//only active emitter spawn new partical
	bool active = false;

	//The particals emitted by this emiters
	//This might be move to partical system class in the future
	vector<Pawn*> particles;

	ParticleEmitter(ParticleSystem* ps, Pawn* p);
	
	virtual void update() override;
	virtual void draw() override;

	//Spawn a new partical
	void spawn();
};