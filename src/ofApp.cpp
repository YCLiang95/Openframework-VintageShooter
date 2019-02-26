#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	PlayerShip* Ship = new PlayerShip();
	Ship->sprite.load("test2.jpg");
	Ship->transform.position = glm::vec3(300, 300, 0);
	gameObjects.push_back(Ship);

	Turret* turret = new Turret();
	turret->sprite.load("test.jpg");
	turret->transform.position = glm::vec3(0, 0, 0);
	turret->transform.parent = &Ship->transform;
	gameObjects.push_back(turret);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).keyPressed(key);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).keyReleased(key);
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).mouseMoved(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
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
