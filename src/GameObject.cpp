#include "GameObject.h"

GameObject::GameObject() {
}

void GameObject::draw() {
	ofFill();
	ofBeginShape();
	for (vector<glm::vec3>::iterator it = verts.begin(); it != verts.end(); ++it)
		ofVertex(*it + position);
	ofEndShape();
}

void GameObject::collision(glm::vec3) {
}