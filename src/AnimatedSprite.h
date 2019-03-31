#pragma once
#include "Sprite.h"

class AnimatedSprite :public Sprite {
public:
	vector<ofImage*> image;
	//Load image from path
	void load(string path);

	void splite(int x, int y, int height, int width, int column, int row);

	void update() override;
	void draw(Transform t) override;
	//offset from image files, not in use yet
	int offset_x, offset_y;
	int position = 0;
	float interval = 100;
	float timeLastUpdate;
	bool play = false;
	int count;
};