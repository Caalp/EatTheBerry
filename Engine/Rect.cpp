#include "Rect.h"


Rect::Rect(int xRight, int xLeft, int yTop, int yBottom):
	right(xRight),
	left(xLeft),
	top(yTop),
	bottom(yBottom)
{
}

int Rect::GetWidth()
{
	return left - right;
}

int Rect::GetHeight()
{
	return bottom - top;
}
