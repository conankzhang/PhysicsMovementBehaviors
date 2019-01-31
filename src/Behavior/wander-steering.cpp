#include "wander-steering.h"

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

	return BehaviorOutput;
}
