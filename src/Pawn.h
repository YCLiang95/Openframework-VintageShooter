#pragma once
#include "GameObject.h"
#include "Sprite.h"

//A pawn is an gameobject that has graphics, and will participate physics/ collision calculation
//For now, this class is mostly empty
class Pawn :
	public GameObject
{
public:
	Pawn();
	~Pawn();

	//A single image static sprite
	Sprite sprite;

	virtual void draw() override;
	virtual void update() override;
};

