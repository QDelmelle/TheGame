#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	s1 = new Missile(500, 500, 100);
	//shooter1 = new Shooter(1000, 500, 150);
	Jonny = new Character(1000, 500, 150, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
	s1->update();
	//shooter1->update();
	ofSoundUpdate();
	Jonny->update();
	Jonny->checkCollisions(s1);
}

//--------------------------------------------------------------
void ofApp::draw(){
	s1->draw();
	//shooter1->draw();
	Jonny->draw();


	// infos generales
	ofDrawBitmapStringHighlight(std::to_string(ofGetElapsedTimef()), 0, 30);
	ofDrawBitmapStringHighlight(std::to_string(ofGetFrameRate()), ofGetWidth()-100, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//shooter1->shoot();
	Jonny->canarder(5, 10);
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
