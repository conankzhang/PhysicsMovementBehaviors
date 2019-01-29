#pragma once

#include "ofVec2f.h"

struct SBehaviorOutput
{
	ofVec2f Linear;
	float Angular;
};

class CBehavior
{
public:
	CBehavior();
	~CBehavior();

	float Weight;
};

