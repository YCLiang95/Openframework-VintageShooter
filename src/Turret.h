#pragma once
#include "Pawn.h"
#include "ParticleEmitter.h"
#include "Bullet.h"

//Player controlled turret
class Turret : public Pawn{
public:
	//Rotate following the mouse
	virtual void mouseMoved(int x, int y) override;
	//Detect space key to fire
	virtual void keyPressed(int key) override;
	virtual void keyReleased(int key) override;

	virtual void update() override;
	virtual void draw() override;

	Turret();
	~Turret() {};

	//The emitter for the gun
	//Since partical system isn't finished yet
	//Emitters are attached to gun for now
	ParticleEmitter gun;

};
