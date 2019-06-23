#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Doodle
{
	// All the private variables can only be accessed internally
private:

	Vector2f d_Position;
	Sprite d_Sprite;
	Texture d_Texture;
	float angle;
	// Which direction(s) is the player currently moving in
	bool d_Left;
	bool d_Right;

	// Doodle's speed in pixels per second
	float d_Speed;

	float horizontal;
	enum Direction
	{
		Front,Left,Right,Back
	};
	Vector2i source;
	int minx;
	int maxx;

public:

	// We will set Doodle up in the constructor
	Doodle();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// Move Doodle in a specific direction
	void moveLeft();
	void moveRight();

	// Stop Doodle moving in a specific direction
	void stopLeft();
	void stopRight();

	// We will call this function once every frame
	void update(float elapsedTime);


};