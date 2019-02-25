#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//vector<glm::vec3> vec;
	//vec.push_back(glm::vec3(0, 0, 0));
	//vec.push_back(glm::vec3(50, 0, 0));
	//vec.push_back(glm::vec3(0, 50, 0));
	//GameObject triangle = GameObject();
	//triangle.verts = vec;
	//triangle.position = glm::vec3(100, 100, 0);
	//gameObjects.push_back(triangle);

	Turret* turret = new Turret();
	turret->sprite.load("E:\Pictures\D0GcNaRV4AEfCqZ.jpg");
	turret->transform.position = glm::vec3(100, 100, 100);
	gameObjects.push_back(turret);

	width = 80;
	height = 80;
	position_rect = glm::vec3(100, 100, 0);

	verts_triangle.push_back(glm::vec3(-50, -50, 0));
	verts_triangle.push_back(glm::vec3(50, 0, 0));
	verts_triangle.push_back(glm::vec3(0, 50, 0));
	position_triangle = glm::vec3(200, 200, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawBox(position_rect, width, height, 1.0);
	ofDrawTriangle(glm::vec3(glm::vec4(verts_triangle[0], 1.0) * rotation) + position_triangle,
		glm::vec3(glm::vec4(verts_triangle[1], 1.0) * rotation) + position_triangle,
		glm::vec3(glm::vec4(verts_triangle[2], 1.0) * rotation) + position_triangle);
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key) {
	case MOUSEEVENTF_LEFTUP:
		click_inside = false;
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).mouseMoved(x, y);
	}
	//float dx = x - position_triangle.x;
	//float dy = y - position_triangle.y;
	//angle = atan2(dx, dy);
	//rotation = glm::rotate(angle, glm::vec3(0.0f, 0.0f, 1.0f));
	//cout << angle << endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (click_inside)
		angle += 0.1f;
	rotation = glm::rotate(angle, glm::vec3(0.0f, 0.0f, 1.0f));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mouse_position.x = x;
	mouse_position.y = y;
	click_inside = insideShape();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

float ofApp::area(glm::vec3 a, glm::vec3 b, glm::vec3 c) {
	return abs((a.x*(b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0f);
}

bool ofApp::insideShape() {
	//method from https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
	glm::vec3 v1 = glm::vec3(glm::vec4(verts_triangle[0], 1.0) * rotation) + position_triangle;
	glm::vec3 v2 = glm::vec3(glm::vec4(verts_triangle[1], 1.0) * rotation) + position_triangle;
	glm::vec3 v3 = glm::vec3(glm::vec4(verts_triangle[2], 1.0) * rotation) + position_triangle;
	float a = area(v1, v2, v3);
	float b = area(v1, v2, mouse_position);
	float c = area(v1, mouse_position, v3);
	float d = area(mouse_position, v2, v3);
	//cout << a << " " << b <<" " << c <<" " << d <<  endl;
	return (b + c + d) <= (a + 1.0f);
}