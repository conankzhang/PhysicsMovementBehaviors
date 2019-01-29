#include "Boid.h"

#include "ofGraphics.h"

CBoid::CBoid() :
	Color(ofColor::black),
	Size(10)
{
}

CBoid::CBoid(const SKinematic& InTransform, const ofColor& InColor, float InSize) :
	Transform(InTransform),
	Color(InColor),
	Size(InSize)
{

}

CBoid::CBoid(const CBoid& Other) :
	Transform(Other.Transform),
	Color(Other.Color),
	Size(Other.Size)
{

}

CBoid::CBoid(CBoid&& Other) :
	Transform(Other.Transform),
	Color(Other.Color),
	Size(Other.Size)
{

}

CBoid& CBoid::operator=(const CBoid& Other)
{
	Transform = Other.Transform;
	Color = Other.Color;
	Size = Other.Size;

	return *this;
}

CBoid& CBoid::operator=(CBoid&& Other)
{
	Transform = Other.Transform;
	Color = Other.Color;
	Size = Other.Size;

	return *this;
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
	ofSetColor(Color);

	ofDrawCircle(Transform.Position, Size);
	DrawBeak();
}

void CBoid::DrawBeak() const
{
	ofVec2f TriangleVertex1, TriangleVertex2, TriangleVertex3 = Transform.Position;

	TriangleVertex1.y += Size;
	TriangleVertex2.y -= Size;
	TriangleVertex3.x += Size * 2;

	ofDrawTriangle(TriangleVertex1, TriangleVertex2, TriangleVertex3);
}
