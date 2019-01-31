#include "ofApp.h"
#include "Entity/Flock.h"

#include "Behavior/basic-motion.h"
#include "Behavior/seek-steering.h"
#include "Behavior/DynamicLookWhereYouAreGoing.h"
#include "Behavior/DynamicFace.h"
#include "Behavior/wander-steering.h"
#include "Behavior/flocking-behavior.h"
#include "Behavior/DynamicSeparation.h"

//=======================================================================================================================
void ofApp::setup()
{
	ofBackground(ofColor::white);
	ofSetCircleResolution(50);

	CurrentBehavior = EBehavior::NONE;

	Target.x = ofGetWindowWidth() / 2;
	Target.y = ofGetWindowHeight() / 2;

	TargetSize = 10.0f;
}

//=======================================================================================================================
void ofApp::update()
{
	if (Flock)
	{
		Flock->Update(ofGetLastFrameTime());
	}
}

//=======================================================================================================================
void ofApp::draw()
{
	ofSetColor(ofColor::black);

	ofDrawBitmapString("Press 1: Basic Motion", 50, 50);
	ofDrawBitmapString("Press 2: Seek Steering", 50, 75);
	ofDrawBitmapString("Press 3: Wander Steering", 50, 100);
	ofDrawBitmapString("Press 4: Flocking Behavior", 50, 125);

	if (CurrentBehavior == EBehavior::SEEK)
	{
		ofSetColor(ofColor::green);
		ofDrawCircle(Target, TargetSize);
	}

	if (Flock)
	{
		Flock->Draw();
	}
}

//=======================================================================================================================
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

//=======================================================================================================================
void ofApp::mousePressed(int x, int y, int button)
{
	Target.x = x;
	Target.y = y;
}

//=======================================================================================================================
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
		Flock = new CFlock(1, WeightedBehaviors);
		WeightedBehaviors.push_back(SWeightedBehavior(new cbasic_motion(), 1));
		break;
	case EBehavior::SEEK:
		Flock = new CFlock(1, WeightedBehaviors);
		WeightedBehaviors.push_back(SWeightedBehavior(new cseek_steering(Target), 1));
		WeightedBehaviors.push_back(SWeightedBehavior(new CDynamicLookWhereYouAreGoing(Target), 1));
		break;
	case EBehavior::WANDER:
		Flock = new CFlock(1, WeightedBehaviors);
		WeightedBehaviors.push_back(SWeightedBehavior(new cwander_steering(Target), 1));
		WeightedBehaviors.push_back(SWeightedBehavior(new CDynamicFace(Target), 1));
		break;
	case EBehavior::FLOCK:
		Flock = new CFlock(10, WeightedBehaviors);
		WeightedBehaviors.push_back(SWeightedBehavior(new cseek_steering(Target), 1));
		WeightedBehaviors.push_back(SWeightedBehavior(new CDynamicLookWhereYouAreGoing(Target), 1));
		WeightedBehaviors.push_back(SWeightedBehavior(new CDynamicSeparation(Flock->GetBoids()), 1));
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
