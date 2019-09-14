#pragma once
#include "Graphics.h"


class ScoreBar
{
public:
	ScoreBar(int x_2) ;
	void DrawScoreBar(Graphics& gfx);
	void UpdatePosition();
private:
	 //int x1;
	 int x2;
};