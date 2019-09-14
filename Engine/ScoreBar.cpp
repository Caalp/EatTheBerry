#include "ScoreBar.h"

ScoreBar::ScoreBar( int x_2)
{
	
	x2 = x_2;
}

void ScoreBar::DrawScoreBar(Graphics & gfx)
{
	gfx.DrawRect({ 10,10 }, { x2,25 }, Colors::Yellow);
}

void ScoreBar::UpdatePosition()
{
	
	x2 += 15;
}
