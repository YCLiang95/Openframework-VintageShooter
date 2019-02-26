#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Button : public GameObject{
public:
	Sprite sprite_normal;
	Sprite sprite_hover;

	bool hover = false;

	void virtual mouseMoved(int x, int y);
	void virtual mousePressed(int x, int y, int button);
	void virtual draw();

	//Button();
	//~Button() {};
};