#include <SDL2/SDL.h>

class GameObject {
    public:
        SDL_Rect Transform;
        SDL_Texture *Texture;
        SDL_Rect *TextureClip;
    public:
        GameObject();
        GameObject(SDL_Rect transform);
        GameObject(SDL_Texture *texture);
        GameObject(SDL_Texture *texture, SDL_Rect transform);
};