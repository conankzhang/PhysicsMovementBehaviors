#pragma once
#include "Kinematic.h"

#include "ofColor.h"
#include "ofVec2f.h"

#include <vector>

struct SBehaviorOutput;
class CBreadcrumb;

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
	void UpdateBreadCrumbs(double DeltaTime);
	void DrawBeak() const;
	void RotateVertex(ofVec2f& Vertex) const;

	std::vector<CBreadcrumb*> BreadCrumbs;

	SKinematic Transform;
	ofColor Color;
	float Size;

	float BreadcrumbDropDistance;
	ofVec2f LastBreadcrumbPosition;
};
