#include"stdafx.h"
#include"pch.h"
#include"doodle.h"
#include"Engine.h"

Doodle::Doodle()
{
	// How fast does Doodle move?
	d_Speed = 400;

	// Associate a texture with the sprite
	d_Texture.loadFromFile("doodle.png");
	d_Sprite.setTexture(d_Texture);
	d_Sprite.setTextureRect(IntRect( 101,1, 101, 101));

	//Rotation
	d_Sprite.setOrigin(d_Sprite.getLocalBounds().height / 2, d_Sprite.getLocalBounds().width / 2);
	d_Right = true;
	d_Left = false;

	// Set the Doodle's starting position
	d_Position.x = 500;
	d_Position.y = 800;
	source.x = 1;
	source.y = Front;
	minx = 0;
	maxx = 1900;
}
Sprite Doodle::getSprite()
{
	return d_Sprite;
}

void Doodle::moveLeft()
{
	d_Left = true;
	source.y = Left;
	d_Sprite.setTextureRect(IntRect(source.x * 101, source.y * 101, 101, 101));
	source.x++;
	if (source.x * 101 >= d_Texture.getSize().x)
		source.x = 0;
}

void Doodle::moveRight()
{
	d_Right = true;
	source.y = Right;
	d_Sprite.setTextureRect(IntRect(source.x * 101, source.y * 101, 101, 101));
	source.x++;
	if (source.x * 101 >= d_Texture.getSize().x)
		source.x = 0;
}

void Doodle::stopLeft()
{
	d_Left = false;
}

void Doodle::stopRight()
{
	d_Right = false;
}

// Move doodle based on the input this frame,
// the time elapsed, and the speed
void Doodle::update(float elapsedTime)
{
	if (d_Right)
	{
		if (d_Position.x > maxx)
		{
			d_Position.x = maxx;
		}
		d_Position.x += d_Speed * elapsedTime;

	}

	if (d_Left)
	{
		if (d_Position.x < minx)
		{
			d_Position.x = minx;
		}
		d_Position.x -= d_Speed * elapsedTime;
	}

	// Now move the sprite to its new position
	d_Sprite.setPosition(d_Position);

}

