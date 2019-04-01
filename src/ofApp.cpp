#include "ofApp.h"

ofApp* ofApp::game;

//--------------------------------------------------------------
void ofApp::setup(){
	game = this;
	ofHideCursor();
	GameObject* cam = new GameObject();
	camera = cam;
	startButton = Button();
	startButton.transform.position = glm::vec3(200, 200, 0);
	startButton.sprite_normal.load("Start_red.png");
	startButton.sprite_hover.load("Start_yellow.png");

	font.load("arial.ttf", 32);
	cout << font.isLoaded() << endl;
	ground.load("Ground.png");
}

void ofApp::startGame() {
	startButton.~Button();
	gui.setup();
	gui.add(guiScore.setup("Score ", std::to_string(score)));
	gui.add(RoF.setup("Fire interval", 1000, 100, 3000));

	debrisSprite = Sprite();
	debrisSprite.load("bullet.png");
	debrisSprite.image.resize(8, 8);

	MouseCursor* mouse = new MouseCursor();
	mouse->sprite = new AnimatedSprite();
	mouse->sprite->load("crosshair.png");
	mouse->sprite->image[0]->resize(160, 32);
	mouse->sprite->splite(0, 0, 32, 32, 5, 1);
	mouse->sprite->interval = 500;
	mouse->sprite->play = true;
	gameObjects.push_back(mouse);

	player = new PlayerShip();
	AnimatedSprite* tankSprite = new AnimatedSprite();
	tankSprite->load("TankChess.png");
	tankSprite->image[0]->resize(512, 128);
	tankSprite->splite(0, 0, 128, 128, 4, 1);
	player->sprite = tankSprite;
	player->transform.position = glm::vec3(300, 300, 0);
	gameObjects.push_back(player);

	debris = new ParticleSystem();
	particleSystems.push_back(debris);

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
	zombie->lifeSpan = 10000;
	zombie->sprite = new Sprite();
	zombie->sprite->load("bullet.png");
	zombie->transform.drag = 0.0f;

	Zombie* smallZombie = new Zombie();
	smallZombie->sprite = zombie->sprite;
	smallZombie->transform.drag = 0.0f;

	ParticleEmitter* spawner1 = new ParticleEmitter(enemies, zombie);
	spawner1->interval = 3000.0f;
	spawner1->particle = zombie;
	spawner1->transform.position = glm::vec3(300, 0, 0);
	spawner1->speed = 1.0f;
	spawner1->transform.angle = PI;
	spawner1->direction = glm::vec3(0.0f, 1.0f, 0.0f);
	//spawner1->active = true;

	ParticleEmitter* spawner2 = new ParticleEmitter(enemies, zombie);
	spawner2->interval = 1000.0f;
	spawner2->particle = zombie;
	spawner2->transform.position = glm::vec3(0, 100, 0);
	spawner2->speed = 1.0f;
	spawner2->transform.angle = PI / 2;
	spawner2->direction = glm::vec3(0.0f, 1.0f, 0.0f);
	//spawner2->active = true;

	enemiesSpawner = new ParticleEmitter(enemies, zombie);

	ofSoundPlayer* bgm = new ofSoundPlayer();
	bgm->load("bgm.wav");
	bgm->setLoop(true);
	bgm->play();

	gameObjects.push_back(spawner1);
	gameObjects.push_back(spawner2);
	particleSystems.push_back(enemies);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameStart) {
		gun->gun->interval = RoF;
		guiScore = std::to_string(score);
		if (ofGetElapsedTimeMillis() - enemiesSpawner->timeLastSpawn > 1000) {
			enemiesSpawner->timeLastSpawn = ofGetElapsedTimeMillis();
			if (rand() % 2 == 1)
				enemiesSpawner->transform.position = glm::vec3(rand() % 2 * 1280, rand() % 720, 0) + camera->transform.position;
			else
				enemiesSpawner->transform.position = glm::vec3(rand() % 1280, rand() % 2 * 720, 0) + camera->transform.position;
			enemiesSpawner->spawn();
			float dx = -enemiesSpawner->transform.position.x + player->transform.getPosition().x;
			float dy = -enemiesSpawner->transform.position.y + player->transform.getPosition().y;
			float angle = -atan2(dx, dy) + PI;
			ImpulseForce f = ImpulseForce();
			f.direction = glm::vec3(cos(angle - PI / 2), sin(angle - PI / 2), 0);
			f.magnitude = rand() % 100 + 100;
			enemies->particles.back()->transform.applyForce(100, f);
		}

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
					Zombie* smallZombie = new Zombie();
					smallZombie->lifeSpan = 3000;
					smallZombie->sprite = &debrisSprite;
					smallZombie->transform.drag = 0;
					ParticleEmitter* spawner1 = new ParticleEmitter(debris, smallZombie);
					spawner1->transform.position = (**it2).transform.position;
					for (int i = 0; i < 100; i++) {
						ImpulseForce f = ImpulseForce();
						f.direction = glm::vec3(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * 2 - 1, static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * 2 - 1, 0);
						f.magnitude = rand() % 100 + 100;
						spawner1->spawn();
						debris->particles.back()->transform.applyForce(10, f);
					}

					(**it2).isDead = true;
					score += 100;
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
	ofClear(0);
	if (!gameStart) 
		startButton.draw();
	else {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				ground.draw(glm::vec3((i - 2) * 1024 + fmod(camera->transform.position.x, 1024), (j - 2) * 1024 + fmod(camera->transform.position.y, 1024), 0));
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
	if (!gameStart) {
		gameStart = true;
		startGame();
	}
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

