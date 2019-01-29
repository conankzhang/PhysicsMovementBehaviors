#pragma once

#include "ofVec2f.h"

struct SBehaviorOutput;

class CKinematic
{
public:
	void Update(const SBehaviorOutput& Behavior, double DeltaTime);

private:
	ofVec2f Position;
	ofVec2f Velocity;

	float Orientation;
	float Rotation;

	float MaxSpeed;
	float MaxAngularSpeed;
};

