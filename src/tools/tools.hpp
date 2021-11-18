#include <SDL2/SDL.h>
#include "windows.h"
#define THROW_SDL_ERROR MessageBox(NULL, SDL_GetError(), NULL, MB_OK)

SDL_Texture* LoadTexture(SDL_Renderer *renderer, const char* path);