#pragma once
#include "SpriteSheet.h"

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
	
	
	void Posun(std::vector<TGameObject*>* otherObjects);
	void Frame();
	bool operator==(TGameObject obj);

private:
	SDL_Rect srcBox;
	/*enum class eKolize : int {
		NONE = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};*/
	bool pom = false;
	enum eIndex : int {
		LEFT = 0,
		RIGHT,
		UP,
		DOWN
	};
protected:
	SDL_Rect dstBox;
	TVec2 vector;


	
	bool kolize[4];
	

	class TOtherObject {
	public:
		SDL_Rect dstBox;
		TVec2 vector;
	public:
		TOtherObject(const SDL_Rect& dstBox, const TVec2& vector) {
			this->dstBox = dstBox;
			this->vector = vector;
		}
	};

	

protected:
	void MistoKolize(std::vector<TGameObject*>* otherObjects);
};

