#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//s1 = new Shape(500, 500, 100);
	shooter1 = new Shooter(1000, 500, 150);
}

//--------------------------------------------------------------
void ofApp::update(){
	//s1->update();
	shooter1->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//s1->draw();
	shooter1->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	shooter1->shoot(0,0);
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
