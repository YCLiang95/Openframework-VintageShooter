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
	Zombie zombie = Zombie();
	zombie.sprite.load("bullet.png");
	zombie.transform.drag = 0.0f;
	ParticleEmitter* spawner1 = new ParticleEmitter();
	spawner1->interval = 3000.0f;
	spawner1->particle = zombie;
	spawner1->transform.position = glm::vec3(300, 0, 0);
	spawner1->speed = 1.0f;
	spawner1->transform.angle = PI;
	spawner1->direction = glm::vec3(0.0f, 1.0f, 0.0f);
	spawner1->active = true;

	ParticleEmitter* spawner2 = new ParticleEmitter();
	spawner2->interval = 1000.0f;
	spawner2->particle = zombie;
	spawner2->transform.position = glm::vec3(0, 100, 0);
	spawner2->speed = 1.0f;
	spawner2->transform.angle = PI / 2;
	spawner2->direction = glm::vec3(0.0f, 1.0f, 0.0f);
	spawner2->active = true;

	enemySpawner->addEmitter(spawner1);
	enemySpawner->addEmitter(spawner2);
	particleSystems.push_back(enemySpawner);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameStart)
		gun->gun.interval = RoF;
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).update();
	}
	for (vector<ParticleSystem*>::iterator it = particleSystems.begin(); it != particleSystems.end(); ++it) {
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
	for (vector<ParticleSystem*>::iterator it = particleSystems.begin(); it != particleSystems.end(); ++it) {
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
