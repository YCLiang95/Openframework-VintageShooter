#include "AnimatedSprite.h"
#include "Sprite.h"

void AnimatedSprite::load(string path) {
	image.clear();
	ofImage* t = new ofImage();
	t->load(path);
	image.push_back(t);
}

void AnimatedSprite::draw(Transform t) {
	ofPushMatrix();
	//Transform based on parent position
	ofTranslate(t.getPosition());
	//transform based on parent rotation
	ofRotate(t.getAngle() * 180 / PI);
	ofPushMatrix();
	//The center of the sprite will be used by default
	ofTranslate(-image[position]->getWidth() / 2, -image[position]->getHeight() / 2);
	image[position]->draw(0, 0);
	ofPopMatrix();
	ofPopMatrix();
}

void AnimatedSprite::splite(int x, int y, int height, int width, int column, int row) {
	count = column * row;
	ofImage* im = image[0];
	image.clear();
	for (int i = 0; i < column; i++)
		for (int j = 0; j < row; j++) {
			ofImage* t = new ofImage();
			t->cropFrom(*im, x + i * width, y + j * height, width, height);
			image.push_back(t);
		}
};

void AnimatedSprite::update() {
	if (play) {
		float dt = ofGetElapsedTimeMillis() - timeLastUpdate;
		if (dt > interval) {
			position++;
			if (position >= count)
				position = 0;
			timeLastUpdate = ofGetElapsedTimeMillis();
		}
	}
	else {
		position = 0;
		timeLastUpdate = ofGetElapsedTimeMillis();
	}
}
