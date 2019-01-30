#include "Boid.h"

#include "Breadcrumb.h"
#include "ofGraphics.h"

CBoid::CBoid() :
	Color(ofColor::black),
	Size(10),
	BreadcrumbDropDistance(50),
	LastBreadcrumbPosition(Transform.Position)
{
	Transform.Position.x = 50;
	Transform.Position.y = 50;
}

CBoid::CBoid(const SKinematic& InTransform, const ofColor& InColor, float InSize) :
	Transform(InTransform),
	Color(InColor),
	Size(InSize),
	BreadcrumbDropDistance(50),
	LastBreadcrumbPosition(Transform.Position)
{

}

CBoid::CBoid(const CBoid& Other) :
	Transform(Other.Transform),
	Color(Other.Color),
	Size(Other.Size),
	BreadcrumbDropDistance(Other.BreadcrumbDropDistance),
	LastBreadcrumbPosition(Other.LastBreadcrumbPosition)
{

}

CBoid::CBoid(CBoid&& Other) :
	Transform(Other.Transform),
	Color(Other.Color),
	Size(Other.Size),
	BreadcrumbDropDistance(Other.BreadcrumbDropDistance),
	LastBreadcrumbPosition(Other.LastBreadcrumbPosition)
{

}

CBoid& CBoid::operator=(const CBoid& Other)
{
	Transform = Other.Transform;
	Color = Other.Color;
	Size = Other.Size;
	BreadcrumbDropDistance = Other.BreadcrumbDropDistance;
	LastBreadcrumbPosition = Other.LastBreadcrumbPosition;

	return *this;
}

CBoid& CBoid::operator=(CBoid&& Other)
{
	Transform = Other.Transform;
	Color = Other.Color;
	Size = Other.Size;
	BreadcrumbDropDistance = Other.BreadcrumbDropDistance;
	LastBreadcrumbPosition = Other.LastBreadcrumbPosition;

	return *this;
}

CBoid::~CBoid()
{
}

void CBoid::Update(const SBehaviorOutput& Behavior, double DeltaTime)
{
	Transform.Update(Behavior, DeltaTime);
	Transform.Position.y += 3;

	UpdateBreadCrumbs(DeltaTime);
}

void CBoid::Draw() const
{
	ofSetColor(Color);

	ofDrawCircle(Transform.Position, Size);
	DrawBeak();

	for (auto BreadCrumb : BreadCrumbs)
	{
		BreadCrumb->Draw();
	}
}

void CBoid::UpdateBreadCrumbs(double DeltaTime)
{
	auto Write = BreadCrumbs.begin();

	for (auto Read = Write, End = BreadCrumbs.end(); Read != End; ++Read)
	{
		if ((*Read)->GetIsAlive())
		{
			if (Read != Write)
			{
				*Write = std::move(*Read);
			}

			++Write;
			(*Read)->Update(DeltaTime);
		}
	}

	BreadCrumbs.erase(Write, BreadCrumbs.end());

	float DistanceToLastBreadCrumb = (Transform.Position - LastBreadcrumbPosition).length();

	if (DistanceToLastBreadCrumb > BreadcrumbDropDistance)
	{
		BreadCrumbs.push_back(new CBreadcrumb(Transform.Position));
		LastBreadcrumbPosition = Transform.Position;
	}
}

void CBoid::DrawBeak() const
{
	ofVec2f TriangleVertex1 = Transform.Position;
	ofVec2f TriangleVertex2 = Transform.Position;
	ofVec2f TriangleVertex3 = Transform.Position;

	TriangleVertex1.y += Size;
	TriangleVertex2.y -= Size;
	TriangleVertex3.x += Size * 2;

	ofDrawTriangle(TriangleVertex1, TriangleVertex2, TriangleVertex3);
}
