#pragma once
#include "Behavior.h"

class cwander_steering : public CBehavior
{
public:
	cwander_steering();
	~cwander_steering();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;
};

