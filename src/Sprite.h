#pragma once
# include "ofMain.h"

//A single image static sprite
//Pretty empty for now
class Sprite {
public:
	ofImage image;
	//Load image from path
	void load(string path);
	//offset from image files, not in use yet
	int offset_x, offset_y;
};