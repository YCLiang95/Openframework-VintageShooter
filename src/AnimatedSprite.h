#pragma once
#include "Sprite.h"

class AnimatedSprite :public Sprite {
public:
	float interval;

	void draw();
};