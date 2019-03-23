#include "Sprite.h"

void Sprite::load(string path) {
	image.loadImage(path);
}

void Sprite::draw(Transform t) {
	ofPushMatrix();
	//Transform based on parent position
	ofTranslate(t.getPosition());
	//transform based on parent rotation
	ofRotate(t.getAngle() * 180 / PI);
	ofPushMatrix();
	//The center of the sprite will be used by default
	ofTranslate(-image.getWidth() / 2, -image.getHeight() / 2);
	image.draw(0, 0);
	ofPopMatrix();
	ofPopMatrix();
}