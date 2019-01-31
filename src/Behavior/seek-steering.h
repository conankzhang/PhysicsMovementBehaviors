#pragma once
#include "Behavior.h"

class cseek_steering : public CBehavior
{
public:
	cseek_steering();
	~cseek_steering();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;
};
