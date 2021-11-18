#include "gameobject.hpp"

GameObject::GameObject(){
    this->Texture = NULL;

    this->Transform.x = 0;
    this->Transform.y = 0;
    this->Transform.h = 1;
    this->Transform.w = 1;

    this->TextureClip = NULL;
}

GameObject::GameObject(SDL_Rect transform){
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

GameObject::GameObject(SDL_Texture *texture, SDL_Rect transform){
    this->Texture = texture;
    this->Transform = transform;

    this->TextureClip = NULL;
}