#include "Star.h"


Star::Star(Vec2i v_pos, Vec2i v_vel):
	pos(v_pos),
	vel(v_vel)
	{
	
}
void Star::Draw(Graphics & gfx)
{
	gfx.DrawSprite(pos.x, pos.y, surface, Colors::White);
}
void Star::update()
{
	
	
	pos.x +=vel.x;
	pos.y += vel.y;

	const int right = pos.x + width;
	if (pos.x < 0)
	{
		pos.x = 0;
		vel.x = -vel.x;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		pos.x = (Graphics::ScreenWidth - 1) - width;
		vel.x = -vel.x;
	}

	const int bottom = pos.y + height;
	if (pos.y < 0)
	{
		pos.y = 0;
		vel.y = -vel.y;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		pos.y = (Graphics::ScreenHeight - 1) - height;
		vel.y = -vel.y;
	}

	
}

bool Star::DetectCollision(const Character& chr) const
{
	const int charright = chr.Get_x() + 20;
	const int starright = pos.x + 18;
	const int starbottom = pos.y + 18;
	const int charbottom = chr.Get_y() + 20;

	
	return chr.Get_x() <= starright && charright >= pos.x &&
		chr.Get_y() <= starbottom && charbottom >= pos.y;
}

Vec2i Star::get_vel() 
{
	const Vec2i GetVel(vel.x, vel.y);
	return GetVel;
}



void Star::set_vel(Vec2i set_vel)
{
	vel.x = set_vel.x;
	vel.y = set_vel.y;
}


