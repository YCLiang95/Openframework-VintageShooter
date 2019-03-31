#pragma once
#include "GameObject.h"
#include "Sprite.h"


//Mouse cursor icon
//Namely the crosshair
class MouseCursor : public GameObject {
public:
	Sprite* sprite;

	virtual void draw() override {
		sprite->draw(transform);
	};

	virtual void mouseMoved(int x, int y) override {
		transform.position.x = x;
		transform.position.y = y;
	};
};