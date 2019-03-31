#pragma once
# include "ofMain.h"
#include "Transform.h"

//A single image static sprite
//Pretty empty for now
class Sprite {
public:
	ofImage image;
	//Load image from path
	void load(string path);

	virtual void draw(Transform t);
	virtual void draw(glm::vec3 position);
	virtual void update() {};
	//offset from image files, not in use yet
	int offset_x, offset_y;
};