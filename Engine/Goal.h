#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Character.h"
class Goal
{
public:
	Goal() =  default;
	Goal( Vec2i pos) ;
	void Draw(Graphics& gfx);
	void SetNewPosition(Vec2i npos);
	bool IsEaten(Character& chr) const;
private:
	Vec2i goal_pos;
	const Surface& surface = Surface("berry.bmp");
};
