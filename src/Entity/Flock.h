#pragma once

#include <vector>
#include "Entity/Boid.h"
#include "Behavior/Behavior.h"

class CFlock
{
public:
	CFlock(int InFlockCount);
	~CFlock();

	void Update(float DeltaTime);
	void Draw() const;

private:
	std::vector<CBoid> Boids;
	std::vector<CBehavior> Behaviors;

	int FlockCount;
};
