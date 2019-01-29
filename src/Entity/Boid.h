#pragma once
#include "Kinematic.h"
#include "ofColor.h"

struct SBehaviorOutput;

class CBoid
{
public:
	CBoid();
	CBoid(const SKinematic& InTransform, const ofColor& InColor, float InSize);
	CBoid(const CBoid& Other);
	CBoid(CBoid&& Other);
	CBoid& operator=(const CBoid& Other);
	CBoid& operator=(CBoid&& Other);
	~CBoid();

	void Update(const SBehaviorOutput& Behavior, double DeltaTime);
	void Draw() const;

private:
	void DrawBeak() const;

	SKinematic Transform;
	ofColor Color;
	float Size;
};
