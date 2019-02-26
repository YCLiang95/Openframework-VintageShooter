#include "Button.h"

void Button::mouseMoved(int x, int y) {
}

void Button::mousePressed(int x, int y, int button) {
}

void Button::draw() {
	ofPushMatrix();
	ofTranslate(transform.getPosition());
	if (hover) {
		ofTranslate(-sprite_hover.image.getWidth() / 2, -sprite_normal.image.getHeight() / 2);
		sprite_hover.image.draw(0, 0);
	} else {
		ofTranslate(-sprite_normal.image.getWidth() / 2, -sprite_normal.image.getHeight() / 2);
		sprite_normal.image.draw(0, 0);
	}
	ofPopMatrix();
}