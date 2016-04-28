#include "Menu.h"
#include "Debug.h"
#include "Game.h"

using namespace sf;

Menu::Menu()
{
	background = Sprite();
	selectionPosition = 0;
	Image backgroundImage = Image();
	if (!backgroundImage.loadFromFile("res/bgmenu.tga"))
		DebugOut("Background Image loading fail...");
	else {
		font = Font();
		Color color(206, 206, 206);
		if (!font.loadFromFile("res/Dead Kansas.ttf"))
			DebugOut("Font loading fail...");
		else
		{
			DebugOut("Font loading ok...");

			// NEW GAME
			newGame = Text();
			newGame.setFont(font);
			newGame.setString("Nouvelle partie");
			newGame.setCharacterSize(50);
			newGame.setColor(color);
			newGame.setPosition(150, 600);

			// QUIT
			quitGame = Text();
			quitGame.setFont(font);
			quitGame.setString("Quitter");
			quitGame.setCharacterSize(50);
			quitGame.setColor(color);
			quitGame.setPosition(850, 600);

			//Selection
			Color bgColor(129, 91, 54);
			selection = new RectangleShape(sf::Vector2f(300, 60));
			selection->setFillColor(bgColor);
			setSelectionSize(0);
			selection->setOutlineThickness(5);
			selection->setOutlineColor(sf::Color(250, 150, 100));


		}
		txBackground = Texture();
		txBackground.loadFromImage(backgroundImage);
		background.setTexture(txBackground);
		Draw();
	}


}

void Menu::Update()
{
}

void Menu::Draw()
{
	Game* game = Game::getInstance();
	game->getWindow()->draw(background);
	game->getWindow()->draw(*selection);
	game->getWindow()->draw(newGame);
	game->getWindow()->draw(quitGame);
}

void Menu::setSelectionSize(int choice) {
	if (choice == 0) {
		selection->setSize(sf::Vector2f(445, 75));
		selection->setPosition(140, 595);
	}
	else {
		selection->setSize(sf::Vector2f(210, 75));
		selection->setPosition(840, 595);
	}
}

void Menu::moveSelection(Vector2f vector) {
	if (vector.x > 0)
		selectionPosition = 1;
	else if (vector.x < 0)
		selectionPosition = 0;
	setSelectionSize(selectionPosition);
}

void Menu::validateSelection() {
	Game* game = Game::getInstance();
	if (selectionPosition == 1) {
		game->getWindow()->close();
	}
	else {
		game->leaveMenu();
	}
}