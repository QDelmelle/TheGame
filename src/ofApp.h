#pragma once

#include "ofMain.h"
#include "core/Shape.h"
#include "core/Shooter.h"
#include "core/Character.h"
#include "instanciable/Johnny.h"
#include "instanciable/Monster.h"
#include "vector"
#include "ofxGui.h"
#include "ofParameter.h"

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
		
		Shape *s1;
		Johnny * John;
		Character * C;
		Monster * Bouboule;

		//gui
		ofxFloatSlider radius;
		ofxColorSlider color;
		ofxVec2Slider centerJohn;
		ofxIntSlider circleResolution;
		ofxToggle filled;
		ofParameter<bool> selectedJohn;
		ofParameter<bool> selectedBouboule;
		bool oldJohn = false, oldBouboule = false;
		ofxLabel screenSize;

		ofxPanel gui;
};
