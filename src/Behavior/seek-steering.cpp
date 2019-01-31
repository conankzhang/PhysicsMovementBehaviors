#include "seek-steering.h"

//=======================================================================================================================
cseek_steering::cseek_steering(const ofVec2f& InTarget) :
	Target(InTarget)
{

}

//=======================================================================================================================
cseek_steering::~cseek_steering()
{
}

//=======================================================================================================================
SBehaviorOutput cseek_steering::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;

	return BehaviorOutput;
}
