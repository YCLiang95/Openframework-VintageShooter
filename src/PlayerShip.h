#pragma once
#include "Pawn.h"
#include "AnimatedSprite.h"

//Player controlled ship
//For now, it just move with key pressed
class PlayerShip : public Pawn {
public:
	virtual void keyPressed(int key) override;
	virtual void keyReleased(int key) override;

	virtual void update() override;

private:
	bool isAccelerating;
	int accerating;
};