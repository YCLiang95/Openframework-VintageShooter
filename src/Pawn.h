#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Pawn :
	public GameObject
{
public:
	Pawn();
	~Pawn();

	Sprite sprite;

	virtual void draw() override;
};

