#include "Flock.h"


CFlock::CFlock(int InFlockCount) :
	FlockCount(InFlockCount)
{
	Boids.clear();

	for (int i = 0; i < FlockCount; i++)
	{
		Boids.push_back(CBoid());
	}
}

CFlock::~CFlock()
{
}

void CFlock::Update(float DeltaTime)
{

}

void CFlock::Draw() const
{
	for (auto Boid : Boids)
	{
		Boid.Draw();
	}
}
