#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
#include "doodle.h"

using namespace sf;
using namespace std;

class Engine
{
private:

	RenderWindow d_Window;

	// Declare a sprite and a Texture for the background
	Sprite d_BackgroundSprite;
	Sprite d_rottenSprite;
	Sprite d_appleSprite;
	Texture d_BackgroundTexture;
	Texture d_rottenTexture;
	Texture d_appleTexture;
	Vector2u TextureSize;	//To store texture size


	Vector2f rottenTextureSize;  //To store texture size
	Vector2f appleTextureSize;
	Vector2u WindowSize;	//to store window size
	// An instance of Bob
	Doodle d_Doodle;
	vector<Sprite>d_rotten;
	vector<Sprite>d_apple;
	int spawnTime = 0;
	int spawnTime1 = 0;

	int lives = 7;
	int score = 0;


	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
	void spawnBalloon();
	void collision();

public:
	// The Engine constructor
	Engine();

	// start will call all the private functions
	void start();

};