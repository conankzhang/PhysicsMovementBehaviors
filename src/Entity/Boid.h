#pragma once
#include "Kinematic.h"

#include "ofColor.h"
#include "ofVec2f.h"

#include <vector>

struct SBehaviorOutput;
class CBreadcrumb;

//=======================================================================================================================
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

	inline ofVec2f GetPosition() const { return Transform.Position; }
	inline ofVec2f GetVelocity() const { return Transform.Velocity; }
	inline float GetSize() const { return Size; }
	inline float GetMaxSpeed() const { return Transform.MaxSpeed; }

private:
	void UpdateBreadCrumbs(double DeltaTime);
	void DrawBeak() const;
	void RotateVertex(ofVec2f& Vertex) const;
	void HandleBoundaries();

	std::vector<CBreadcrumb*> BreadCrumbs;

	SKinematic Transform;
	ofColor Color;
	float Size;

	float BreadcrumbDropDistance;
	ofVec2f LastBreadcrumbPosition;
};
