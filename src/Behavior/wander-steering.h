#pragma once
#include "Behavior.h"

//=======================================================================================================================
class cwander_steering : public CBehavior
{
public:
	cwander_steering(const ofVec2f InTarget);
	~cwander_steering();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	const ofVec2f& Target;

	float RandomBinomial();
};

