#include "wander-steering.h"

#include "Entity/Boid.h"

//=======================================================================================================================
cwander_steering::cwander_steering(const ofVec2f InTarget) :
	Target(InTarget)
{

}

//=======================================================================================================================
cwander_steering::~cwander_steering()
{
}

//=======================================================================================================================
SBehaviorOutput cwander_steering::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;

	ofVec2f Direction = ofVec2f::zero();
	Direction.x = cos(InBoid.GetOrientation());
	Direction.y = sin(InBoid.GetOrientation());

	BehaviorOutput.Linear = Direction * InBoid.GetMaxSpeed();
	BehaviorOutput.Angular = InBoid.GetMaxAngularSpeed() * RandomBinomial();

	return BehaviorOutput;
}

float cwander_steering::RandomBinomial()
{
	return static_cast<float>(rand()) - static_cast<float>(rand());
}
