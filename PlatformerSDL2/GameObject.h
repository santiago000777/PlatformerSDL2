#pragma once
#include "SpriteSheet.h"

class TGameObject
{
public:
		// ctor s parametry
	TGameObject(SDL_Renderer* renderer, SDL_Rect destBox, const std::string& path, SDL_Rect fromBox, SDL_Rect windowRect);
		// copy ctor (zakazany)
	TGameObject(const TGameObject& rhs) = delete;
		// move ctor (zakazany)
	TGameObject(TGameObject&& rhs) = delete;
		// Destructor
	~TGameObject();
		// copy prirazeni
	void operator=(const TGameObject& rhs);
		// move prirazeni
	void operator=(TGameObject&& rhs);


	bool operator==(TGameObject obj);

	void SetBackground(TBackGround* bg);

	void Render();
	virtual void HandleEvents();
	void Posun(std::vector<TGameObject*>* otherObjects, float delta);
	void Clear();

private:
	SDL_Rect windowRect;
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

