#pragma once
#include "Texture.h"

class TGameObject
{
public:
	TTexture texture;

public:
	TGameObject() = default;
	TGameObject(SDL_Renderer* renderer, TVec2 pos, TVec2 size, std::string path, TVec2 fromXY, float percentX, float percentY);
	void Init(SDL_Renderer* renderer, TVec2 pos, TVec2 size, std::string path, TVec2 fromXY, float percentX, float percentY);
	TGameObject(SDL_Renderer* renderer, TVec2 pos, TVec2 size, TColor* color);

	void SetWindowSize(SDL_Rect* rect);
	void SetBackground(const std::string& path);
	void SetBackground(TBackGround* bg);


	void SetBackground(TColor color);

	TVec2* GetVector();

	~TGameObject();
	enum class eBodKolize : int {
		NONE = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
	
	void Posun(SDL_Rect* rect2, TVec2* posun2);
	void Frame();

private:
	SDL_Rect srcBox;

protected:
	SDL_Rect dstBox;
	TVec2 vector;
	eBodKolize posledniKolize;

protected:
	eBodKolize MistoKolize(SDL_Rect* rect2, TVec2* posun2);
};

