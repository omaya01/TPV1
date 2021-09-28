#pragma once
#include "SDL.h"
#include "Unicorn.h"

#include <iostream>
#include <vector>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
using namespace std;

class Game
{ 
public:

	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;

	//Unicorn* unicorns;
	std::vector<Unicorn*> unicorns;

	int init();
	void run();
	void clear();
};

