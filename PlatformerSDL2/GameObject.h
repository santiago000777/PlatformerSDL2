#pragma once
#include "SpriteSheet.h"

class TGameObject
{
public:
	/*
	copy ctor
	op=
	~des
	*/
	TGameObject(SDL_Renderer* renderer, SDL_Rect destBox, const std::string& path, SDL_Rect fromBox);
	~TGameObject();
	void Init(SDL_Renderer* renderer, SDL_Rect dstBox, const std::string& path, SDL_Rect fromBox);
	bool operator==(TGameObject obj);

	void SetWindowSize(SDL_Rect* rect);
	void SetBackground(const std::string& path);
	void SetBackground(TBackGround* bg);

	void Render();
	virtual void HandleEvents();
	void Posun(std::vector<TGameObject*>* otherObjects, float delta);
	void Clear();

private:
	SDL_Rect* windowRect;
	TBackGround* background;
	SDL_Texture* texture;

	enum eIndex : int {
		LEFT = 0,
		RIGHT,
		UP,
		DOWN
	};

protected:
	void MistoKolize(std::vector<TGameObject*>* otherObjects, float delta);

	SDL_Renderer* renderer;
	TVec2 vector;
	SDL_Rect dstBox;
	SDL_Rect srcBox;

	int pom = 4;
	bool kolize[4];

};

