#pragma once
#include "AbstractEntity.h"

using namespace sf;
class Menu : AbstractEntity {
public:
	Menu(RenderWindow &mainWindow);
	void Update();
	void Draw();
private:
	Sprite background;
	RenderWindow &target;
	Text newGame;
	Text quitGame;
};