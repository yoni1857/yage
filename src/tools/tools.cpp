#include "tools.hpp"

// Takes a .BMP files and loads it into a surface, then into a texture.
SDL_Texture* LoadTexture(SDL_Renderer *renderer, const char* path){
    SDL_Surface *tempSurf = SDL_LoadBMP(path);
    if(tempSurf == NULL){
        THROW_SDL_ERROR;
        exit(-1);
    }
    SDL_Texture* tempTex = SDL_CreateTextureFromSurface(renderer, tempSurf);
    SDL_FreeSurface(tempSurf);
    return tempTex;
}