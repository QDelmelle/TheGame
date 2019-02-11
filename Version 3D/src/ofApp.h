#pragma once

#include "ofMain.h"
#include "Shape.h"
#include "Shooter.h"
#include "Character.h"
#include "vector"

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
		void moveCamera();
		
		Shape *s1;
		Shooter * shooter1;
		Character * Jonny;
		Shape * m;
		std::vector<Shape*> L;

		ofCamera cam;
		ofLight light;
};
