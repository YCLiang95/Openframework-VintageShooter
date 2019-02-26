#pragma once
#include "GameObject.h"
#include "Sprite.h"


//My own custom button class
//Not finished yet, might not be included in the future
//Becuase OF gui class are convienet
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