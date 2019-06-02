#include "stdafx.h"
#include "pch.h"
#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame
	d_Window.clear(Color::White);

	// Draw the background
	TextureSize = d_BackgroundTexture.getSize();	//get size of texture
	
	WindowSize = d_Window.getSize();	//get size of window

	float ScaleX = (float)WindowSize.x / TextureSize.x;
	float ScaleY = (float)WindowSize.y / TextureSize.y;

	d_BackgroundSprite.setTexture(d_BackgroundTexture);
	d_BackgroundSprite.setScale(ScaleX, ScaleY);

	d_Window.draw(d_BackgroundSprite);
	d_Window.draw(d_Doodle.getSprite());
	
	d_rottenSprite.setTexture(d_rottenTexture);
	d_appleSprite.setTexture(d_appleTexture);

	d_rotten.push_back(d_rottenSprite);
	d_apple.push_back(d_appleSprite);
	
	for (size_t i = 0; i < d_rotten.size(); i++)
	{
		d_Window.draw(d_rotten[i]);
	}

	for (size_t i = 0; i < d_apple.size(); i++)
	{
		d_Window.draw(d_apple[i]);
	}

	// Show everything we have just drawn
	d_Window.display();
}
