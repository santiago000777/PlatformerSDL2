#pragma once
#include "GameObject.h"
class TPlayer :
    public TGameObject {
public:
    TPlayer() {}
    void KeyboardInput();
    void AddObjects();
private:
    enum eControls : short {
        UP = 'w',
        LEFT = 'a',
        DOWN = 's',
        RIGHT = 'd'
    };


};

