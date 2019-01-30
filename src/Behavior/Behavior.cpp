#include "Behavior.h"

SBehaviorOutput::SBehaviorOutput() :
	Linear(ofVec2f::zero()),
	Angular(0.0f)
{

}

SWeightedBehavior::SWeightedBehavior(CBehavior* InBehavior, float InWeight) :
	Behavior(InBehavior),
	Weight(InWeight)
{

}
