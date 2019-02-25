#pragma once
#include "Pawn.h"

class Turret : public Pawn{
public:
	virtual void mouseMoved(int x, int y) override;
};
