#include "stdafx.h"
#include "pch.h"
#include "Engine.h"

Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	d_Window.create(VideoMode(resolution.x, resolution.y),"The Game",Style::Fullscreen);

	// Load the background into the texture
	// Be sure to scale this image to your screen size
	d_BackgroundTexture.loadFromFile("background.jpg");
	d_rottenTexture.loadFromFile("rotten.png");
	d_appleTexture.loadFromFile("apple.png");

	// Associate the sprite with the texture
	d_BackgroundSprite.setTexture(d_BackgroundTexture);
}

void Engine::start()
{
	// Timing
	Clock clock;

	while (d_Window.isOpen())
	{
		// Restart the clock and save the elapsed time into dt
		Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();
		input();
		spawnBalloon();
		update(dtAsSeconds);
		draw();
	}
}