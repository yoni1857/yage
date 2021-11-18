#include <SDL2/SDL.h>

class GameObject {
    public:
        // Stores X and Y positions as well as Height and Width.
        SDL_FRect Transform;
        // Self explanatory.
        SDL_Texture *Texture;
        // If texture is NULL we will use this color to draw. If both are NULL will not draw at all.
        SDL_Color *Color;
        // Incase only a part of the texture needs to be drawn.
        SDL_Rect *TextureClip;
    public:
        GameObject();
        GameObject(SDL_FRect transform);
        GameObject(SDL_Texture *texture);
        GameObject(SDL_Texture *texture, SDL_FRect transform);
        void Draw(SDL_Renderer *renderer);
};