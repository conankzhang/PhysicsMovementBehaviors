#include "DynamicLookWhereYouAreGoing.h"

#include "Entity/Boid.h"
//=======================================================================================================================
CDynamicLookWhereYouAreGoing::CDynamicLookWhereYouAreGoing(ofVec2f InTarget)
{
	DynamicAlign.SetTarget(InTarget);
}

//=======================================================================================================================
CDynamicLookWhereYouAreGoing::~CDynamicLookWhereYouAreGoing()
{
}

//=======================================================================================================================
SBehaviorOutput CDynamicLookWhereYouAreGoing::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;

	if (InBoid.GetVelocity().length() == 0)
	{
		return BehaviorOutput;
	}

	float TargetOrientation = atan2(InBoid.GetVelocity().y, InBoid.GetVelocity().x);

	DynamicAlign.SetTargetOrientation(TargetOrientation);
	BehaviorOutput = DynamicAlign.GetBehaviorOutput(InBoid);

	return BehaviorOutput;
}
