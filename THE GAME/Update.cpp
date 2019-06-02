#include "stdafx.h"
#include"pch.h"
#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	d_Doodle.update(dtAsSeconds);
}