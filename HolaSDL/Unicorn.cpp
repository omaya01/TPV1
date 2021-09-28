#include "Unicorn.h"

#include <iostream>

Unicorn::Unicorn(int w, int h) {
	alive_ = true;
	image_ = SDL_LoadBMP("../BMPs/unicorn.bmp");
	setRandomPos(w, h);
}

void Unicorn::setRandomPos(int w, int h) {
	pos_.x = rand() % (w - image_->w) - (image_->w / 2) + (image_->w / 2);
	pos_.y = rand() % (h - image_->h) - (image_->h / 2) + (image_->h / 2);
}

void Unicorn::draw(SDL_Surface* surface) {
	SDL_BlitSurface(image_, NULL, surface, &pos_);
}

void Unicorn::click(int x, int y) {
	SDL_Point p;
	p.x = x;
	p.y = y;
	if (SDL_PointInRect(&p, &pos_)) {
		std::cout << "dead";
		alive_ = false;
	}
}


// 
// 
// 
// for() Unicorn* u;
// vector unicorns
// for(unicorns) 
// u.loadmedia
// u.setrandompos
// u.draw
//
//
//
//