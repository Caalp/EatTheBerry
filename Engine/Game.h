/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Star.h"
#include "Goal.h"
#include <random>
#include <vector>
#include "ScoreBar.h"
#include "SoundEffect.h"
#include "FrameTimer.h"
#include "Surface.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
	void GameOver(Graphics& gfx);
	

private:
	void ComposeFrame();
	void UpdateModel();
	
private:
	const int x = 365;
	const int y = 250;
	MainWindow & wnd;
	Graphics gfx;
	Character chr;
	
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xdist;
	std::uniform_int_distribution<int> ydist;
	Goal berry;
	std::vector<Star> vStar;
	ScoreBar Score;
	FrameTimer ft;
	static constexpr int nStar{ 5 };
	static constexpr int nGoal{ 100 };
	bool collision;
	bool BerryEaten = false;
	SoundEffect coin = SoundEffect({ L"Sounds\\coin.wav" });
	Surface surface = Surface("game_over.bmp");
	 int x1 = 10;
	 int x2 = 25;
	
};