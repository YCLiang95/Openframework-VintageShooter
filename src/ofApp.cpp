#include "ofApp.h"

ofApp* ofApp::game;

//--------------------------------------------------------------
void ofApp::setup(){
	game = this;
	GameObject* cam = new GameObject();
	camera = cam;
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
	mouse->sprite = new Sprite();
	mouse->sprite->load("crosshair.png");
	gameObjects.push_back(mouse);

	player = new PlayerShip();
	AnimatedSprite* tankSprite = new AnimatedSprite();
	tankSprite->load("TankChess.png");
	tankSprite->image[0]->resize(512, 128);
	tankSprite->splite(0, 0, 128, 128, 4, 1);
	player->sprite = tankSprite;
	player->transform.position = glm::vec3(300, 300, 0);
	gameObjects.push_back(player);

	bullets = new ParticleSystem();
	Turret* turret = new Turret(bullets);
	turret->sprite = new Sprite();
	turret->sprite->load("Turret.png");
	turret->sprite->image.resize(128, 128);
	turret->transform.position = glm::vec3(0, 0, 0);
	turret->transform.parent = &player->transform;
	gun = turret;
	gameObjects.push_back(turret);
	particleSystems.push_back(bullets);

	enemies = new ParticleSystem();
	Zombie* zombie = new Zombie();
	zombie->sprite = new Sprite();
	zombie->sprite->load("bullet.png");
	zombie->transform.drag = 0.0f;

	ParticleEmitter* spawner1 = new ParticleEmitter(enemies, zombie);
	spawner1->interval = 3000.0f;
	spawner1->particle = zombie;
	spawner1->transform.position = glm::vec3(300, 0, 0);
	spawner1->speed = 1.0f;
	spawner1->transform.angle = PI;
	spawner1->direction = glm::vec3(0.0f, 1.0f, 0.0f);
	spawner1->active = true;

	ParticleEmitter* spawner2 = new ParticleEmitter(enemies, zombie);
	spawner2->interval = 1000.0f;
	spawner2->particle = zombie;
	spawner2->transform.position = glm::vec3(0, 100, 0);
	spawner2->speed = 1.0f;
	spawner2->transform.angle = PI / 2;
	spawner2->direction = glm::vec3(0.0f, 1.0f, 0.0f);
	spawner2->active = true;

	gameObjects.push_back(spawner1);
	gameObjects.push_back(spawner2);
	particleSystems.push_back(enemies);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameStart) {
		gun->gun->interval = RoF;
		for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
			(**it).update();
		}
		for (vector<ParticleSystem*>::iterator it = particleSystems.begin(); it != particleSystems.end(); ++it) {
			(**it).update();
		}

		for (vector<Pawn*>::iterator it1 = bullets->particles.begin(); it1 != bullets->particles.end(); ++it1)
			for (vector<Pawn*>::iterator it2 = enemies->particles.begin(); it2 != enemies->particles.end(); ++it2)
				if (Pawn::collide(*it1, *it2)) {
					//(**it1).isDead = true;
					(**it2).isDead = true;
				}

		if (player->transform.position.x + camera->transform.position.x < 300)
			camera->transform.position.x = 300 - player->transform.position.x;
		else if (player->transform.position.x + camera->transform.position.x > 980)
			camera->transform.position.x = 980 - player->transform.position.x;

		if (player->transform.position.y + camera->transform.position.y < 200)
			camera->transform.position.y = 200 - player->transform.position.y;
		else if (player->transform.position.y + camera->transform.position.y > 520)
			camera->transform.position.y = 520 - player->transform.position.y;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (!gameStart) startButton.draw();
	gui.draw();
	ofPushMatrix();
	//Transform based on parent position
	ofTranslate(camera->transform.position);
	for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(**it).draw();
	}
	for (vector<ParticleSystem*>::iterator it = particleSystems.begin(); it != particleSystems.end(); ++it) {
		(**it).draw();
	}
	ofPopMatrix();
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
		(**it).mouseMoved(x - camera->transform.position.x, y - camera->transform.position.y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0) 
		for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
			(**it).keyPressed(' ');
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == 0)
		for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
			(**it).keyReleased(' ');
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
