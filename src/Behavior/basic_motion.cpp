#include "basic_motion.h"

SBehaviorOutput cbasic_motion::GetBehaviorOutput()
{
	SBehaviorOutput BehaviorOutput;

	BehaviorOutput.Linear.x = 25;
	BehaviorOutput.Linear.y = 25;
	BehaviorOutput.Angular = 1;

	return BehaviorOutput;
}
