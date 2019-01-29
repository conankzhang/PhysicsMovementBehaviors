#include "Kinematic.h"

#include "Behavior/Behavior.h"

void CKinematic::Update(const SBehaviorOutput& Behavior, double DeltaTime)
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
