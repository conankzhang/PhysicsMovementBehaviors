#include "Kinematic.h"

#include "Behavior/Behavior.h"

SKinematic::SKinematic() :
	Position(ofVec2f::zero()),
	Velocity(ofVec2f::zero()),
	Orientation(0.0f),
	Rotation(0.0f),
	MaxSpeed(100.0f),
	MaxAngularSpeed(100.0f)
{

}

void SKinematic::Update(const SBehaviorOutput& Behavior, double DeltaTime)
{
	Position += Velocity * DeltaTime;
	Orientation += Rotation * DeltaTime;

	Velocity += Behavior.Linear * DeltaTime;
	if (Velocity.length() > MaxSpeed)
	{
		Velocity.normalize();
		Velocity *= MaxSpeed;
	}

	Rotation += Behavior.Angular * DeltaTime;
	if (Rotation > MaxAngularSpeed)
	{
		Rotation = MaxAngularSpeed;
	}
}
