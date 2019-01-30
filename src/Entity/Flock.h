#pragma once

#include "Behavior/Behavior.h"

#include <vector>

class CBoid;

class CFlock
{
public:
	CFlock(int InFlockCount, std::vector<SWeightedBehavior>* InWeightedBehaviors);
	~CFlock();

	void Update(float DeltaTime);
	void Draw() const;

private:
	SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid);

	std::vector<CBoid *> Boids;
	std::vector<SWeightedBehavior>* WeightedBehaviors;
};
