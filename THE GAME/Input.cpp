#include "stdafx.h"
#include"pch.h"
#include "Engine.h"

void Engine::input()
{
	// Handle the player quitting
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		d_Window.close();
	}

	// Handle the player moving
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		d_Doodle.moveLeft();
	}
	else
	{
		d_Doodle.stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		d_Doodle.moveRight();
	}
	else
	{
		d_Doodle.stopRight();
	}
}