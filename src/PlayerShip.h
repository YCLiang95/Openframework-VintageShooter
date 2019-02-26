#pragma once
#include "Pawn.h"

class PlayerShip : public Pawn {
public:
	virtual void keyPressed(int key) override;
	virtual void keyReleased(int key) override;

	virtual void update() override;
private:
	bool isAccelerating;
};