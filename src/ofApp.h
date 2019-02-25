#pragma once

#include "ofMain.h"
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
		bool ofApp::insideShape();
		float area(glm::vec3 a, glm::vec3 b, glm::vec3 c);

		bool click_inside;

		vector<GameObject*> gameObjects;
		glm::vec3 mouse_position;
		float angle;
		
		vector<glm::vec3> verts_triangle;
		glm::vec3 position_triangle;
		glm::mat4 rotation;

		int height, width;
		glm::vec3 position_rect;
};
