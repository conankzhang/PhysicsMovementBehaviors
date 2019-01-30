#pragma once

#include "ofVec2f.h"

struct SBehaviorOutput
{
	ofVec2f Linear;
	float Angular;

	SBehaviorOutput();
};

class CBehavior
{
public:
	virtual SBehaviorOutput GetBehaviorOutput() = 0;
};

struct SWeightedBehavior
{
	CBehavior* Behavior;
	float Weight;

	SWeightedBehavior(CBehavior* InBehavior, float InWeight);
};
