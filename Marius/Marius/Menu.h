#pragma once
#include "AbstractEntity.h"

using namespace sf;
class Menu : AbstractEntity {
public:
	Menu(RenderWindow &mainWindow);
	void Update();
	void Draw();
	void setSelectionSize(int choice);
	void moveSelection(Vector2f vector);
	void validateSelection();
private:
	Sprite background;
	RenderWindow &target;
	Text newGame;
	Text quitGame;
	Font font;
	Texture txBackground;
	RectangleShape *selection;
	int selectionPosition;
};