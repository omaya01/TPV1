#include "Game.h"

int Game::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "could not initialize sdl2: " << SDL_GetError() << endl;
        return -1;
    }
    window = SDL_CreateWindow(
        "octopus killer 1.0",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        cout << "could not create window: " << SDL_GetError() << endl;
        return -1;
    }
    screenSurface = SDL_GetWindowSurface(window);

    return 0;

}

void Game::run()
{
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));
    srand(time(NULL));
    
    SDL_Event e;
    bool quit = false;
    float time = -1;
    float best = -1;
    while (!quit) {
        if (unicorns.size()==0) {
            for (int i = 0; i < 3; i++) {
                unicorns.push_back(new Unicorn(SCREEN_WIDTH, SCREEN_HEIGHT));
            }
            if (time != -1) {
                float aux = (SDL_GetTicks() - time)/1000;
                cout << "you took " << aux << " seconds to kill all unicorns!\n";
                if (best != -1 && aux < best)best = aux;
                else best = aux;
            }
            time = SDL_GetTicks();
        }
        
        int i = 0;
        for (Unicorn* u : unicorns) {
            if (u->isAlive()) {
                u->draw(screenSurface);
                SDL_UpdateWindowSurface(window);
            }
            else {
                u->clear(screenSurface, window);
                delete unicorns[i];
                unicorns.erase(unicorns.begin() + i);
            }
            i++;
        }

        bool clicked = false;
        while (!clicked && SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                for (Unicorn* u : unicorns)u->click(x, y);
                clicked = true;
            }
        }        
    }
    cout << "Your best time was: " << best << "\n";
}

void Game::clear()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

