#pragma once
#include "Character.h"
#include "Graphics.h"
#include <vector>


class Star 
{
public:
	
	Star(Vec2i v_pos,Vec2i v_vel);
	void Draw(Graphics& gfx);
	void update();
	bool DetectCollision(const Character& chr) const ;
	Vec2i get_vel() ;
	void set_vel(Vec2i set_vel);
	
	
	

private:
	Vec2i pos;
	Vec2i vel;
	Character chr;
	const Surface& surface = Surface("poo.bmp");
	static constexpr int  width = 24;
	static constexpr int height = 24;
};