#include "Flock.h"

#include "Entity/Boid.h"

CFlock::CFlock(int InFlockCount)
{
	Boids.reserve(InFlockCount);
	for (int i = 0; i < InFlockCount; i++)
	{
		Boids.push_back(new CBoid());
	}
}

CFlock::~CFlock()
{
	for (auto Boid : Boids)
	{
		delete Boid;
	}

	Boids.clear();
}

void CFlock::Update(float DeltaTime)
{
	for (auto Boid : Boids)
	{
		if (Boid)
		{
			SBehaviorOutput BehaviorOutput = GetBehaviorOutput(*Boid);
			Boid->Update(BehaviorOutput, DeltaTime);
		}
	}
}

void CFlock::Draw() const
{
	for (auto Boid : Boids)
	{
		if (Boid)
		{
			Boid->Draw();
		}
	}
}

SBehaviorOutput CFlock::GetBehaviorOutput(const CBoid& Boid)
{
	SBehaviorOutput ReturnBehaviorOutput;

	for (auto Behavior : Behaviors)
	{
		SBehaviorOutput BehaviorOutput = Behavior.GetBehaviorOutput();
		ReturnBehaviorOutput.Linear += BehaviorOutput.Linear * Behavior.Weight;
		ReturnBehaviorOutput.Angular += BehaviorOutput.Angular * Behavior.Weight;
	}

	return ReturnBehaviorOutput;
}
