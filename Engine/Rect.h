#pragma once
#include "Vec2.h"
class Rect
{
public:
	Rect() = default;
	Rect(int xRight, int xLeft, int yTop, int yBottom);
	int GetWidth();
	int GetHeight();
	
public:
	int right;
	int left;
	int top;
	int bottom;
};
