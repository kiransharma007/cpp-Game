#include "stdafx.h"
#include "pch.h"
#include "Engine.h"

using namespace sf;

void Engine::spawnBalloon()
{
	if (spawnTime < 100)
		spawnTime++;
	if (spawnTime >= 100)
	{
		d_rottenSprite.setPosition((rand() % int(d_Window.getSize().x - d_rottenSprite.getOrigin().x)), 0.f);
		d_rotten.push_back(d_rottenSprite);
		spawnTime = 0;
	}
	if (spawnTime1 < 100)
		spawnTime1++;

	if (spawnTime1 >= 100)
	{
		d_appleSprite.setPosition((rand() % int(d_Window.getSize().x - d_appleSprite.getOrigin().x)), 0.f);
		d_apple.push_back(d_appleSprite);
		spawnTime1 = 0;
	}


	for (size_t i = 0; i < d_rotten.size(); i++)
	{
		d_rotten[i].move(0.0f, 0.5f);
	}

	for (size_t i = 0; i < d_apple.size(); i++)
	{
		d_apple[i].move(0.0f, 0.5f);
	}

}
