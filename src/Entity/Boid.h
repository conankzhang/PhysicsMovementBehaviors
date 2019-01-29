#pragma once
#include "Kinematic.h"

struct SBehaviorOutput;

class CBoid
{
public:
	CBoid();
	~CBoid();

	void Update(const SBehaviorOutput& Behavior, double DeltaTime);
	void Draw() const;

private:
	CKinematic Transform;
};
