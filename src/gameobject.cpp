#include "gameobject.hpp"

GameObject::GameObject(){
    this->Texture = NULL;

    this->Transform.x = 0;
    this->Transform.y = 0;
    this->Transform.h = 1;
    this->Transform.w = 1;

    this->TextureClip = NULL;
}

GameObject::GameObject(SDL_FRect transform){
    this->Texture = NULL;
    this->Transform = transform;

    this->TextureClip = NULL;
}

GameObject::GameObject(SDL_Texture *texture){
    this->Texture = texture;
    
    this->Transform.x = 0;
    this->Transform.y = 0;
    this->Transform.h = 1;
    this->Transform.w = 1;

    this->TextureClip = NULL;
}

GameObject::GameObject(SDL_Texture *texture, SDL_FRect transform){
    this->Texture = texture;
    this->Transform = transform;

    this->TextureClip = NULL;
}

void GameObject::Draw(SDL_Renderer *renderer){
    if(this->Texture != NULL)
        SDL_RenderCopyF(renderer, this->Texture, this->TextureClip, &this->Transform);
    else if (this->Texture == NULL && this->Color != NULL)
    {
        SDL_SetRenderDrawColor(renderer, this->Color->r, this->Color->g, this->Color->b, this->Color->a);
        SDL_RenderDrawRectF(renderer, &this->Transform);
    }
}