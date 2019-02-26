#pragma once
#include "GameObject.h"
#include "Sprite.h"

class MouseCursor : public GameObject {
public:
	Sprite sprite;

	virtual void draw() override {
		ofPushMatrix();
		ofTranslate(transform.getPosition());
		ofTranslate(-sprite.image.getWidth() / 2, -sprite.image.getHeight() / 2);
		sprite.image.draw(0, 0);
		ofPopMatrix();
	};

	virtual void mouseMoved(int x, int y) override {
		transform.position.x = x;
		transform.position.y = y;
	};
};