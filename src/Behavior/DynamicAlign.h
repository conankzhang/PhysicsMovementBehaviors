#pragma once
#include "Behavior.h"

//=======================================================================================================================
class CDynamicAlign : public CBehavior
{
public:
	CDynamicAlign(const ofVec2f& InTarget);
	~CDynamicAlign();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	float MapToRange(float InRotation);

	const ofVec2f& Target;

	float TargetAngleThreshold;
	float SlowAngleThreshold;
	float TimeToTarget;
	float MaxRotation;
	float MaxAngularAcceleration;
};

