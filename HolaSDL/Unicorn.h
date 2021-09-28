#pragma once

#include "../SDL2-2.0.16/include/SDL.h"
#include <string>

class Unicorn {
protected:
	SDL_Surface* image_ = nullptr;
	SDL_Rect pos_;
	bool alive_;
public:
	Unicorn(int w, int h);
	bool isAlive() { return alive_; };
	void setDead() { alive_ = false; };
	//bool loadMedia(std::string filename);
	void setRandomPos(int w, int h);
	void draw(SDL_Surface* surface);
	void clear();
	void click(int x, int y);
};