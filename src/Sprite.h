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

	void draw(Transform t);
	//offset from image files, not in use yet
	int offset_x, offset_y;
};