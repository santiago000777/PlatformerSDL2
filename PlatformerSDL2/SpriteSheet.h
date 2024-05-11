#pragma once
#include "Texture.h"

class TSpriteSheet {
public:
	TTexture texture;

public:
	TSpriteSheet(std::vector<TVec4>& vec);

private:
	std::vector<TVec4> spritePos;

private:

};

