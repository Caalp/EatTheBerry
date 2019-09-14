#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "MainWindow.h"
#include "Vec2.h"



class Character
{
public:
	
	Character() = default;
	Character(Vec2i& pos,Vec2i& vel);
	 
	void MoveObject(MainWindow& wnd,float dt);
	void ScreenFrame(Graphics& gfx);
	virtual void Draw(Graphics& gfx);
	int  Get_x() const;
	int Get_y() const;
	int Get_vx() const;
	int Get_vy() const;
	void set_vx(int vx_new);
	void set_vy(int vy_new);
	

	
private:
	const Surface& surface = Surface("dude.bmp");
	Vec2i position;
	Vec2i velocity;
	

	
};