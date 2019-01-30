#include "ofApp.h"
#include "Entity/Flock.h"

#include "Behavior/Behavior.h"
#include "Behavior/basic_motion.h"

//--------------------------------------------------------------
void ofApp::setup(){
	BackgroundColor = ofColor::white;

	Flock = make_shared<CFlock>(1);

	SWeightedBehavior* BasicMotionBehavior = new SWeightedBehavior();
	BasicMotionBehavior->Behavior = new cbasic_motion();
	BasicMotionBehavior->Weight = 1;
	BasicMotionBehaviors.push_back(BasicMotionBehavior);

	Flock->SetWeightedBehaivors(make_shared<std::vector<SWeightedBehavior *>>(BasicMotionBehaviors));
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
