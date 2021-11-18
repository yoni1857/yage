#include "tools.hpp"

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

float Lerp(float a, float b, float t){
    return a+t*(b-a);
}

float Clamp(float val, float min, float max){
    if(val > max)
        return max;
    if (val < min)
        return min;
    return val;
}

double Time::CalculateDeltaTime(){    
    currentTime = SDL_GetPerformanceCounter();
    deltaTime = (double)((currentTime-lastTime) / (double)SDL_GetPerformanceFrequency());
    lastTime= currentTime;
}

double Time::DeltaTime(){
    return deltaTime;
} 