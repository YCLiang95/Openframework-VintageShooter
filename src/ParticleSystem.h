#pragma once
#include"Pawn.h"

//Not Implemented yet
//A Partical system will controll mutilple emitter

class ParticleSystem {
public:
	void update();
	vector<Pawn*> particles;
	void draw();
	void addParticle(Pawn* particle);
};