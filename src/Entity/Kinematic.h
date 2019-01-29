#pragma once

#include "ofVec2f.h"

struct SBehaviorOutput;

struct SKinematic
{
	void Update(const SBehaviorOutput& Behavior, double DeltaTime);

	ofVec2f Position;
	ofVec2f Velocity;

	float Orientation;
	float Rotation;

	float MaxSpeed;
	float MaxAngularSpeed;
};

