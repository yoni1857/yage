#include "game.hpp"

Game::Game (char* title, Uint16 width, Uint16 height) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        THROW_SDL_ERROR;
        SDL_Quit();
        exit(-1);
    }
    this->Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(this->Window == NULL){
        THROW_SDL_ERROR;
        SDL_Quit();
        exit(-1);
    }
    this->Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(this->Renderer == NULL){
        THROW_SDL_ERROR;
        SDL_DestroyWindow(this->Window);
        SDL_Quit();
        exit(-1);
    }
}

// No need to touch this unless you really want to.
void Game::Run(){
    this->_start();
    while (!this->_shouldQuit)
    {
        SDL_PollEvent(&this->_eventHandler);
        this->_handleEvents(this->_eventHandler);
        this->_update();
    }
    _quit();
}

// Runs when the game is done. Cleans stuff up.
void Game::_quit(){
    SDL_DestroyWindow(this->Window);
    SDL_DestroyRenderer(this->Renderer);
    SDL_Quit();
}

// Runs once when the game starts
void Game::_start(){
    this->t_bg = LoadTexture(this->Renderer,"blue-sky.bmp");
    this->square = new GameObject(LoadTexture(this->Renderer,"metal-texture.bmp"));
    this->square->Transform.h = 10;
    this->square->Transform.w = 10;
}

// Handles events...
void Game::_handleEvents(SDL_Event e){
    this->Time++;
    SDL_GetWindowSize(this->Window, &this->sW, &this->sH);
    switch (e.type){
        case SDL_QUIT:
            this->_shouldQuit = true;
            break;
        case SDL_KEYDOWN:
            this->_handleKeyDown(e.key.keysym.sym);
            break;
        case SDL_KEYUP:
            this->_handleKeyUp(e.key.keysym.sym);
            break;
    }
}

// This handles a key being pressed
void Game::_handleKeyDown(SDL_Keycode keycode){
    switch(keycode){
        case SDLK_UP:
            this->square->Transform.y-=this->deltaTime;
            break;
        case SDLK_DOWN:
            this->square->Transform.y+=this->deltaTime;
            break;
        case SDLK_RIGHT:
            this->square->Transform.x+=this->deltaTime;
            break;
        case SDLK_LEFT:
            this->square->Transform.x-=this->deltaTime;
            break;
    }
}

// This handles a key being released
void Game::_handleKeyUp(SDL_Keycode keycode){

}

// This runs every frame
void Game::_update(){
    this->currentTime = this->Time;
    this->deltaTime = (this->currentTime-this->lastTime);
    SDL_RenderClear(this->Renderer);

    if(!once){
        this->square->Transform.x = this->sW/2-(this->square->Transform.w/2);
        this->square->Transform.y = this->sH/2-(this->square->Transform.h/2);
        once = true;
    }
    
    SDL_RenderCopy(this->Renderer, 
    this->t_bg, NULL,NULL);
    
    SDL_RenderCopy(this->Renderer, this->square->Texture, this->square->TextureClip, &this->square->Transform);

    SDL_RenderPresent(this->Renderer);
    this->lastTime = this->currentTime;
}