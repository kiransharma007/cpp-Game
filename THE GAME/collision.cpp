
#include "stdafx.h"
#include "pch.h"
#include "doodle.h"
#include "Engine.h"


using namespace sf;

void Engine::collision()
{
	for (size_t i = 0; i < d_apple.size(); i++)
	{
		if(d_Doodle.getSprite().getGlobalBounds().intersects(d_apple[i].getGlobalBounds()))
		{
			d_apple.erase(d_apple.begin() + i);
			score++;
		}
	}
	for (size_t i = 0; i < d_rotten.size(); i++)
	{
		if (d_Doodle.getSprite().getGlobalBounds().intersects(d_rotten[i].getGlobalBounds()))
		{
			d_rotten.erase(d_rotten.begin() + i);
			score--;
			rotten_collision++;
			if (rotten_collision % 1000 == 0)
				lives--;
		}
	}
}
