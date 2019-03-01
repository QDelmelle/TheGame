#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	s1 = new Missile(500, 500, 100);
	John = new Johnny(200, 200, 150);
	Bouboule = new Monster(1500, 500, 150);

	//setup gui => dans le futur, 1 gui par objet
	gui.setup("Paramètres de John"); // most of the time you don't need a name
	///gui.add(filled.setup("fill", true));
	///gui.add(radius.setup("radius", 140, 10, 300));
	gui.add(centerJohn.setup("center", ofVec2f(ofGetWidth()*.5, ofGetHeight()*.5), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
	gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	///gui.add(circleResolution.setup("circle res", 5, 3, 90));
	///gui.add(twoCircles.setup("two circles"));
	///gui.add(ringButton.setup("ring"));
	gui.add(screenSize.setup("screen size", ofToString(ofGetWidth()) + "x" + ofToString(ofGetHeight())));
}

//--------------------------------------------------------------
void ofApp::update(){
	s1->update();
	ofSoundUpdate();
	John->update();
	Bouboule->update();
	John->checkCollisions(s1);
	John->checkCollisions(Bouboule);
}

//--------------------------------------------------------------
void ofApp::draw(){
	s1->draw();
	John->draw();
	Bouboule->draw();

	// infos generales
	ofDrawBitmapStringHighlight(std::to_string(ofGetElapsedTimef()), 0, 30);
	ofDrawBitmapStringHighlight(std::to_string(ofGetFrameRate()), ofGetWidth()-100, 15);

	//gui
	ofSetBackgroundColor(color);
	John->setPos( (ofVec2f)centerJohn);
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//shooter1->shoot();
	switch (key)
	{
	case ' ':
		John->canarder(5, 10);
		break;
	case 'b':
		Bouboule->move(ofVec2f(100, 100));
		break;
	case 'f':
		s1->move(ofVec2f(100, 100));
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
