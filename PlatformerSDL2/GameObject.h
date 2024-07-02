#pragma once
#include "SpriteSheet.h"

class TGameObject
{
public:
	
public:
	TGameObject() = default;
	TGameObject(SDL_Renderer* renderer, SDL_Rect destBox, const std::string& path, SDL_Rect fromBox);
	void Init(SDL_Renderer* renderer, SDL_Rect dstBox, const std::string& path, SDL_Rect fromBox);
	bool operator==(TGameObject obj);
	~TGameObject();

	void SetWindowSize(SDL_Rect* rect);
	void SetBackground(const std::string& path);
	void SetBackground(TBackGround* bg);

	TVec2* GetVector();

	void Render();
	void Posun(std::vector<TGameObject*>* otherObjects);
	void Clear();

private:
	SDL_Rect* windowRect;
	TBackGround* background;
	SDL_Renderer* renderer;

	enum eIndex : int {
		LEFT = 0,
		RIGHT,
		UP,
		DOWN
	};

protected:
	SDL_Texture* texture;
	TVec2 vector;
	SDL_Rect dstBox;
	SDL_Rect srcBox;

	bool kolize[4];
	
protected:
	void MistoKolize(std::vector<TGameObject*>* otherObjects);
};

