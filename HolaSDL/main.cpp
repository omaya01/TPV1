
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"

#include <vector>

using namespace std;

int main(int argc, char* argv[]){

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game g = Game();

	if (g.init() == -1)
		exit(-1);

	g.run();
	g.clear();


	return 0;
}



