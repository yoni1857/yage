#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <map>
#include "gameobject.hpp"
#include "tools/tools.hpp"

class Game {
    // Members
    public:
        SDL_Window *Window = NULL;
        SDL_Renderer *Renderer = NULL;
    private:
        bool _shouldQuit = false;
        SDL_Event _eventHandler;

        SDL_Texture *t_bg;
        GameObject *square = NULL;

        bool once = false;

        int sW; int sH;

        float deltaTime;
        int lastTime;
        int currentTime;
        int Time;


    // Methods
    public:
        Game(char* title, Uint16 width, Uint16 height);
        void Run();
    private:
        void _quit();
        void _start();
        void _update();
        void _handleEvents(SDL_Event e);
        void _handleKeyDown(SDL_Keycode keycode);
        void _handleKeyUp(SDL_Keycode keycode);
};