#pragma once

#include <vector>
#include "Behavior/Behavior.h"

class CBoid;

class CFlock
{
public:
	CFlock(int InFlockCount);
	~CFlock();

	void Update(float DeltaTime);
	void Draw() const;

private:
	SBehaviorOutput GetBehaviorOutput(const CBoid& Boid);

	std::vector<CBoid *> Boids;
	std::vector<CBehavior> Behaviors;
};
