#pragma once
#include "Behavior.h"

//=======================================================================================================================
class cflocking_behavior :
	public CBehavior
{
public:
	cflocking_behavior();
	~cflocking_behavior();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;
};

