#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	s1 = new Shape(500, 500, 100);
	Johnny = new Johnny(200, 200, 150);
	Bouboule = new Monster(1500, 500, 150);
}

//--------------------------------------------------------------
void ofApp::update(){
	s1->update();
	ofSoundUpdate();
	Johnny->update();
	Bouboule->update();
	Johnny->checkCollisions(s1);
	Johnny->checkCollisions(Bouboule);
	Bouboule->checkCollisions(s1);
	Bouboule->checkCollisions(Johnny);
}

//--------------------------------------------------------------
void ofApp::draw(){
	s1->draw();
	Johnny->draw();
	Bouboule->draw();

	// infos generales
	ofDrawBitmapStringHighlight(std::to_string(ofGetElapsedTimef()), 0, 30);
	ofDrawBitmapStringHighlight(std::to_string(ofGetFrameRate()), ofGetWidth()-100, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//shooter1->shoot();
	switch (key)
	{
	case ' ':
		Johnny->canarder(5, 10);
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
