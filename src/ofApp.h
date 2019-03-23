#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "main.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		static ofApp* game;

		ofxPanel gui;
		ofxFloatSlider RoF;
		Turret* gun;

		Button startButton;
		bool gameStart = false;
		vector<GameObject*> gameObjects;
		vector<ParticleSystem*> particleSystems;
		void startGame();
};
