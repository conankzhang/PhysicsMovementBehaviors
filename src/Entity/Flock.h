#pragma once

#include "Behavior/Behavior.h"

#include <vector>

class CBoid;

class CFlock
{
public:
	CFlock(int InFlockCount);
	~CFlock();

	void Update(float DeltaTime);
	void Draw() const;

	void SetWeightedBehaivors(std::shared_ptr<std::vector<SWeightedBehavior *>> InWeightedBehaviors) { WeightedBehaviors = InWeightedBehaviors; }

private:
	SBehaviorOutput GetBehaviorOutput(const CBoid& Boid);

	std::vector<CBoid *> Boids;
	std::shared_ptr<std::vector<SWeightedBehavior *>> WeightedBehaviors;
};
