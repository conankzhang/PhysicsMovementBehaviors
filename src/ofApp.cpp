#include "ofApp.h"
#include "Entity/Flock.h"

#include "Behavior/basic-motion.h"
#include "Behavior/seek-steering.h"

void ofApp::setup()
{
	BackgroundColor = ofColor::white;

	CurrentBehavior = EBehavior::BASIC;

	WeightedBehaviors.push_back(SWeightedBehavior(new cbasic_motion(), 1));
	Flock = new CFlock(1, WeightedBehaviors);
}

void ofApp::update()
{
	if (Flock)
	{
		Flock->Update(ofGetLastFrameTime());
	}
}

void ofApp::draw()
{
	ofBackground(BackgroundColor);

	if (Flock)
	{
		Flock->Draw();
	}
}

void ofApp::keyPressed(int key)
{
	EBehavior DesiredBehavior = EBehavior::BASIC;

	switch (key)
	{
	case '1':
		DesiredBehavior = EBehavior::BASIC;
		break;
	case '2':
		DesiredBehavior = EBehavior::SEEK;
		break;
	case '3':
		DesiredBehavior = EBehavior::WANDER;
		break;
	case '4':
		DesiredBehavior = EBehavior::FLOCK;
		break;
	}

	if (CurrentBehavior != DesiredBehavior)
	{
		HandleNewBehavior(DesiredBehavior);
	}
}

void ofApp::HandleNewBehavior(EBehavior DesiredBehavior)
{
	if (Flock)
	{
		delete Flock;
		Flock = nullptr;

		WeightedBehaviors.clear();
	}

	switch (DesiredBehavior)
	{
	case EBehavior::BASIC:
		WeightedBehaviors.push_back(SWeightedBehavior(new cbasic_motion(), 1));
		Flock = new CFlock(1, WeightedBehaviors);
		break;
	case EBehavior::SEEK:
		WeightedBehaviors.push_back(SWeightedBehavior(new cseek_steering(), 1));
		Flock = new CFlock(1, WeightedBehaviors);
		break;
	case EBehavior::WANDER:
		break;
	case EBehavior::FLOCK:
		break;
	}

	CurrentBehavior = DesiredBehavior;
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
