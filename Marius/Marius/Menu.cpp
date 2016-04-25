#include "Menu.h"
#include "Debug.h"
#include "Game.h"

using namespace sf;

Menu::Menu(RenderWindow &refWindow) : target(refWindow)
{
	background = Sprite();
	Image backgroundImage;
	if (!backgroundImage.loadFromFile("res/bgmenu.tga"))
		DebugOut("Background Image loading fail...");
	else {
		Font font;
		Color color(206, 206, 206);
		if (!font.loadFromFile("res/Dead Kansas.ttf"))
			DebugOut("Font loading fail...");
		else
		{
			DebugOut("Font loading ok...");

			// NEW GAME
			newGame.setFont(font);
			newGame.setString("Nouvelle partie");
			newGame.setCharacterSize(28);
			newGame.setColor(color);
			newGame.setPosition(400, 600);

			// QUIT
			quitGame.setFont(font);
			quitGame.setString("Quitter");
			quitGame.setCharacterSize(28);
			quitGame.setColor(color);
			quitGame.setPosition(750, 600);

		}
		Texture texture;
		texture.loadFromImage(backgroundImage);
		background.setTexture(texture);
		Draw();
	}
		

}

void Menu::Update()
{

}

void Menu::Draw()
{
	target.draw(background);
	target.draw(newGame);
	target.draw(quitGame);
}
