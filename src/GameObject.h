#pragma once

#include "ofMain.h"
#include "Transform.h"

class GameObject {

public:
	int id;

	Transform transform;

	//void virtual move(glm::vec3);
	void virtual update();
	virtual void draw();
	GameObject();
	~GameObject() {};

	void virtual keyPressed(int key) {};
	void virtual keyReleased(int key) {};
	void virtual mouseMoved(int x, int y) {};
	void virtual mouseDragged(int x, int y, int button) {};
	void virtual mousePressed(int x, int y, int button) {};
	void virtual mouseReleased(int x, int y, int button) {};

	void collision(glm::vec3);

};