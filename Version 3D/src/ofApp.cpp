#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//shooter1 = new Shooter(1000, 500, 150);
	Jonny = new Character(1000, 500, 150, 100);

	//camera
	cam.setPosition(100, 100, 800);

	//light
	light.setPosition(400, 400, 1000);
	light2.setPosition(400, 400, -1000);

	ofSetSmoothLighting(true);
	ofSetBackgroundColor(100);

	ofEnableDepthTest(); //without it, we can see through objects
}

//--------------------------------------------------------------
void ofApp::update(){
	//shooter1->update();
	ofSoundUpdate();
	Jonny->update();
	moveCamera();
}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin(); //begin see
	light.enable();
	light2.enable();

	ofDrawAxis(500);

	//shooter1->draw();
	Jonny->draw();


	// infos generales
	ofDrawBitmapString(std::to_string(ofGetElapsedTimef()), 0, 15);
	ofDrawBitmapString(std::to_string(ofGetFrameRate()), ofGetWidth()-100, 100);
	ofDrawBitmapString("ofGetMouseY() : " + std::to_string(ofGetMouseY()), 0, 100);
	ofDrawBitmapString("ofGetMouseX() : " + std::to_string(ofGetMouseX()), 0, 115);

	cam.end(); //end see
	light.disable();
	light2.disable();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//shooter1->shoot();
	if(key==' ')
		Jonny->canarder(5, 10);
	if (key == 's')
		Jonny->smile();

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

//--------------------------------------------------------------
void ofApp::moveCamera() {

	if (mouseX == ofGetWidth()-1) {
		cam.setPosition(cam.getX() + 20, cam.getY(), cam.getZ());
	}
	else if (mouseX == 0) {
		cam.setPosition(cam.getX() - 20, cam.getY(), cam.getZ());
	}
	else if (mouseY == 0) {
		cam.setPosition(cam.getX(), cam.getY() + 20, cam.getZ());
	}
	else if (mouseY == ofGetHeight()-1) {
		cam.setPosition(cam.getX(), cam.getY() - 20, cam.getZ());
	}
}