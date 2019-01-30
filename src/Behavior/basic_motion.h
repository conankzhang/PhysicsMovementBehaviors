#pragma once

#include "Behavior.h"

class cbasic_motion : public CBehavior
{
public:
	virtual SBehaviorOutput GetBehaviorOutput() override;
};
