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
		sf::Texture texture;
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
}
