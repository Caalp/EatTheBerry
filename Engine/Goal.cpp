#include "Goal.h"

Goal::Goal(Vec2i pos)
{
	goal_pos.x = pos.x;
	goal_pos.y = pos.y;
}



void Goal::Draw(Graphics& gfx)
{
	
	gfx.DrawSprite(goal_pos.x, goal_pos.y,surface,Colors::White);
}

void Goal::SetNewPosition(Vec2i npos)
{
	goal_pos.x = npos.x;
	goal_pos.y = npos.y;
}

bool Goal::IsEaten(Character& chr) const
{
	const int charright = chr.Get_x() + 20;
	const int berryright = goal_pos.x + 18;
	const int berrybottom = goal_pos.y + 18;
	const int charbottom = chr.Get_y() + 20;


	return chr.Get_x() <= berryright && charright >= goal_pos.x &&
		chr.Get_y() <= berrybottom && charbottom >= goal_pos.y;
	
}
