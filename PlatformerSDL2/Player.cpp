#include "Player.h"

void TPlayer::KeyboardInput() {
	vector.x = 0;
	vector.y = 0;
	if (PressedKey(eControls::UP))
		vector.y = -1;
	if (PressedKey(eControls::LEFT))
		vector.x = -1;
	if (PressedKey(eControls::DOWN))
		vector.y = 1;
	if (PressedKey(eControls::RIGHT))
		vector.x = 1;
}
