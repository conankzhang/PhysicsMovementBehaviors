#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	BackgroundColor = ofColor(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(BackgroundColor);

	ofSetColor(0, 0, 0);
	ofVec2f Position;
	Position.x = 50;
	Position.y = 50;
	ofDrawCircle(Position, 50);

	ofVec2f TrianglePosition1 = Position;
	TrianglePosition1.y += 50;
	ofVec2f TrianglePosition2 = Position;
	TrianglePosition2.y -= 50;
	ofVec2f TrianglePosition3 = Position;
	TrianglePosition3.x += 100;

	ofDrawTriangle(TrianglePosition1, TrianglePosition2, TrianglePosition3);
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
