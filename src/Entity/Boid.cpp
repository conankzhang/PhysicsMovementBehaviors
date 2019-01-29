#include "Boid.h"

CBoid::CBoid()
{
}


CBoid::~CBoid()
{
}

void CBoid::Update(const SBehaviorOutput& Behavior, double DeltaTime)
{
	Transform.Update(Behavior, DeltaTime);
}

void CBoid::Draw() const
{

}
