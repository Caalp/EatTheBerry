#include "Character.h"
Character::Character(Vec2i& pos, Vec2i& vel):
	position{ pos },
	velocity{vel}
	
{
	

}
void Character::MoveObject(MainWindow& wnd, float dt)
{
	
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		position.x += velocity.x;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		position.x -= velocity.x;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		position.y += velocity.y;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		position.y -= velocity.y;
	}
}

void Character::ScreenFrame(Graphics& gfx)
{
	if (position.x > gfx.ScreenWidth - 20)
	{
		position.x = gfx.ScreenWidth - 20;
	}
	if (position.y > gfx.ScreenHeight - 20)
	{
		position.y = gfx.ScreenHeight - 20;
	}
	if (position.y <= 1)
	{
		position.y = 1;
	}
	if (position.x <= 0)
	{
		position.x = 0;
	}
}

void Character::Draw(Graphics& gfx)
{
	gfx.DrawSprite(position.x, position.y, surface, Colors::Magenta);
}

int Character::Get_x() const
{
	return position.x;
}

int Character::Get_y() const
{
	return position.y;
}

int Character::Get_vx() const
{
	return velocity.x;
}

int Character::Get_vy() const
{
	return velocity.y;
}

void Character::set_vx(int vx_new)
{
	velocity.x = vx_new;
}

void Character::set_vy(int vy_new)
{
	velocity.y = vy_new;
}





