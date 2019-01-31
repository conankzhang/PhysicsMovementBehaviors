#pragma once
#include "Behavior.h"

//=======================================================================================================================
class CDynamicAlign : public CBehavior
{
public:
	CDynamicAlign();
	~CDynamicAlign();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;
	inline void SetTargetOrientation(float InTargetOrientation) { TargetOrientation = InTargetOrientation; }

	inline void SetTarget(ofVec2f InTarget) { Target = InTarget; }
private:
	float MapToRange(float InRotation);

	ofVec2f Target;

	float TargetOrientation;
	float TargetAngleThreshold;
	float SlowAngleThreshold;
	float TimeToTarget;
	float MaxRotation;
	float MaxAngularAcceleration;
};

