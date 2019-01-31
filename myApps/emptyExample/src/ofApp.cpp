#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	etoile = new Etoile(200, 200, 100);
	ss = new ShootingStar(400, 400, 200);
}

//--------------------------------------------------------------
void ofApp::update(){
	etoile->set(mouseX, mouseY, 100); //set -> updatePos
	ss->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	etoile->draw();
	ofDrawBitmapStringHighlight(std::to_string(etoile->x), glm::vec3(0, 15, 0));
	ss->draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 's': 
		printf("feu!");
		ss->shoot(etoile->x, etoile->y);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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