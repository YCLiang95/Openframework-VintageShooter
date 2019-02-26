#pragma once
#include "Pawn.h"
#include "ParticalEmitter.h"

class Turret : public Pawn{
public:
	virtual void mouseMoved(int x, int y) override;
	virtual void keyPressed(int key) override;
	virtual void keyReleased(int key) override;
	virtual void update() override;
	virtual void draw() override;

	Turret();
	~Turret() {};

	ParticalEmitter gun;

};
