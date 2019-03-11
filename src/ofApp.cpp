#include "ofApp.h"

ofApp* ofApp::game;

//--------------------------------------------------------------
void ofApp::setup(){
	game = this;
	startButton = Button();
	startButton.transform.position = glm::vec3(200, 200, 0);
	startButton.sprite_normal.load("Start_red.png");
	startButton.sprite_hover.load("Start_yellow.png");
}

void ofApp::startGame() {
	startButton.~Button();
	gui.setup();
	gui.add(RoF.setup("Fire interval", 1000, 100, 3000));

	MouseCursor* mouse = new MouseCursor();
	mouse->sprite.load("crosshair.png");
	gameObjects.push_back(mouse);

	PlayerShip* Ship = new PlayerShip();
	Ship->sprite.load("ship.png");
	Ship->transform.position = glm::vec3(300, 300, 0);
	gameObjects.push_back(Ship);

	Turret* turret = new Turret();
	turret->sprite.load("Turret.png");
	turret->transform.position = glm::vec3(0, 0, 0);
	turret->transform.parent = &Ship->transform;
	gun = turret;
	gameObjects.push_back(turret);

	ParticleSystem* enemySpawner = new ParticleSystem();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameStart)
		gun->gun.interval = RoF;
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (!gameStart) startButton.draw();
	gui.draw();
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (!gameStart && key == ' ') {
		gameStart = true;
		startGame();
	}
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
