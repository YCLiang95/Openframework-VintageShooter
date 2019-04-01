#pragma once
#include "GameObject.h"
#include "AnimatedSprite.h"


//Mouse cursor icon
//Namely the crosshair
class MouseCursor : public GameObject {
public:
	AnimatedSprite* sprite;

	virtual void draw() override {
		sprite->draw(transform);
	};

	virtual void update() override{
		sprite->update();
	}

	virtual void mouseMoved(int x, int y) override {
		transform.position.x = x;
		transform.position.y = y;
	};
};