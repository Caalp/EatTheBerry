/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <chrono>



Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	chr( Vec2i(400,300) , Vec2i( 30*0.25, 30*0.25 )),
	rng(rd()),
	xdist( 0,770),
	ydist(0,540),
	berry(Vec2i(xdist(rng), ydist(rng))),
	Score(25)
	
	
	
{
	std::uniform_int_distribution<int> vDist(-2.5, 2.5f);
	for (int i = 0; i < nStar; ++i)
	{
		
		vStar.emplace_back(Vec2i(xdist(rng), ydist(rng)), Vec2i(vDist(rng), vDist(rng)));
	
	}
}


void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}


void Game::UpdateModel()
{
	
	static const float dt = ft.PerFrame();
	BerryEaten = berry.IsEaten(chr);
	if (BerryEaten)
	{
		berry.SetNewPosition(Vec2i(xdist(rng), ydist(rng)));

		berry.Draw(gfx);
		Score.DrawScoreBar(gfx);
		Score.UpdatePosition();
		coin.Play(rng);
		
	}
	else
	{
		
		Score.DrawScoreBar(gfx);
		
		berry.Draw(gfx);
		
		
	}

		for (int i = 0; i < nStar ; ++i)
		{
			
			vStar[i].Draw(gfx);
			
			collision =vStar[i].DetectCollision(chr);
			
			if (collision)
			{
				gfx.DrawSprite(375, 280, surface, Colors::Black);
				chr.set_vx(0);
				chr.set_vy(0);
				for (Star& star : vStar)
				{
					star.set_vel({0,0});
					
					
				}
			}
			
		}
	
	for (int i = 0; i < nStar ; ++i)
	{
		vStar[i].update();
		
	}
	chr.MoveObject(wnd,dt);
	chr.ScreenFrame(gfx);	

}

void Game::ComposeFrame()
{
	chr.Draw(gfx);
	 
	
	
}





