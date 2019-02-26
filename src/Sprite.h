#pragma once
# include "ofMain.h"

class Sprite {
public:
	ofImage image;
	
	void load(string path);

	int offset_x, offset_y;
};