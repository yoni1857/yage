#include <SDL2/SDL.h>
#include <iostream>
#include "windows.h"
#define THROW_SDL_ERROR MessageBox(NULL, SDL_GetError(), NULL, MB_OK)

// Takes a .BMP files and loads it into a surface, then into a texture.
SDL_Texture* LoadTexture(SDL_Renderer *renderer, const char* path);

// Linear interpolation
float Lerp(float a, float b, float t);

// Self explanatory
float Clamp(float val, float min, float max);

class Time {
    private:
        inline static long currentTime;
        inline static long lastTime;
        inline static double deltaTime;
    public:
        // Make sure to run this once per frame in order for DeltaTime() to function properly.
        static double CalculateDeltaTime();
        // When calculating speed, multiply it by this in order to make it consistent accross framerates.
        static double DeltaTime();
};