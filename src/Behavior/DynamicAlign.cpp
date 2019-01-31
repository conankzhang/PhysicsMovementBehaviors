#include "DynamicAlign.h"

#include "Entity/Boid.h"

//=======================================================================================================================
CDynamicAlign::CDynamicAlign(const ofVec2f& InTarget) :
	Target(InTarget),
	TargetAngleThreshold(0.05f),
	SlowAngleThreshold(0.1f),
	TimeToTarget(0.01f),
	MaxRotation(0.1f),
	MaxAngularAcceleration(0.1f)
{

}

//=======================================================================================================================
CDynamicAlign::~CDynamicAlign()
{

}

//=======================================================================================================================
SBehaviorOutput CDynamicAlign::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;

	ofVec2f Direction = Target - InBoid.GetPosition();
	if (Direction.length() == 0)
	{
		return BehaviorOutput;
	}

	float TargetOrientation = atan2(Direction.y, Direction.x);
	float Rotation = TargetOrientation - InBoid.GetOrientation();

	Rotation = MapToRange(Rotation);
	float RotationSize = abs(Rotation);
	float TargetRotation = 0.0f;
	if (RotationSize < TargetAngleThreshold)
	{
		return BehaviorOutput;
	}

	if (RotationSize > SlowAngleThreshold)
	{
		TargetRotation = MaxRotation;
	}
	else
	{
		TargetRotation = MaxRotation * RotationSize / SlowAngleThreshold;
	}

	TargetRotation = Rotation / RotationSize;
	float DeltaVelocity = TargetRotation - InBoid.GetRotation();
	float Acceleration = DeltaVelocity / TimeToTarget;

	if (Acceleration > MaxAngularAcceleration)
	{
		Acceleration = MaxAngularAcceleration;
	}

	BehaviorOutput.Angular = Acceleration;

	return BehaviorOutput;
}

float CDynamicAlign::MapToRange(float InRotation)
{
	float Rotation = InRotation;

	while (Rotation > PI)
	{
		Rotation -= 2 * PI;
	}

	while (Rotation < -PI)
	{
		Rotation += 2 * PI;
	}

	return Rotation;
}
