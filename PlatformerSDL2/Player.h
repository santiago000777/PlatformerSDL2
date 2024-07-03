#pragma once
#include "GameObject.h"
class TPlayer : public TGameObject {
public:
    TPlayer(SDL_Renderer* renderer, SDL_Rect dstBox, const std::string& path, SDL_Rect from);
    ~TPlayer();

    void HandleEvents() override;
    
private:
    enum eControls : short {
        UP = 'w',
        LEFT = 'a',
        DOWN = 's',
        RIGHT = 'd'
    };


};

