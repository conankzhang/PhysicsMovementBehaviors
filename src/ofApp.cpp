#include "ofApp.h"
#include "Entity/Flock.h"

#include "Behavior/basic-motion.h"

//--------------------------------------------------------------
void ofApp::setup(){
	BackgroundColor = ofColor::white;

	WeightedBehaviors.push_back(SWeightedBehavior(new cbasic_motion(), 1));
	Flock = new CFlock(1, &WeightedBehaviors);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (Flock)
	{
		Flock->Update(ofGetLastFrameTime());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(BackgroundColor);

	if (Flock)
	{
		Flock->Draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
