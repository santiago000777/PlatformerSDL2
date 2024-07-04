#pragma once
#include "GameObject.h"
class TPlayer : public TGameObject {
public:
        // ctor s parametry
    TPlayer(SDL_Renderer* renderer, SDL_Rect dstBox, const std::string& path, SDL_Rect from, SDL_Rect windowRect);
        // copy ctor (zakazany)
    TPlayer(const TPlayer& rhs) = delete;
        // move ctor (zakazany)
    TPlayer(TPlayer&& rhs) = delete;
        // Destructor
    ~TPlayer();
        // copy prirazeni
    void operator=(const TPlayer& rhs);
        // move prirazeni
    void operator=(TPlayer&& rhs);

    void HandleEvents() override;
    
private:
    enum eControls : short {
        UP = 'w',
        LEFT = 'a',
        DOWN = 's',
        RIGHT = 'd'
    };
};

