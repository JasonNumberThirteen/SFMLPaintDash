#ifndef PAINT_DASH_GAME_APPLICATION_H
#define PAINT_DASH_GAME_APPLICATION_H

#include <SFML/Graphics.hpp>

#include "scene/mainMenuScene.hpp"

namespace PaintDash
{
	namespace core
	{
		class GameApplication;
	}
}

class PaintDash::core::GameApplication
{
	public:
		GameApplication(sf::VideoMode videoMode, const sf::String &title, uint32_t style, sf::State state);
		void init();
	private:
		sf::RenderWindow window;
		sf::Font gameFont;
		PaintDash::graphics::Sprite cursorSprite;
		PaintDash::scenes::MainMenuScene mainMenuScene;
		void update();
		void draw();
		void updateCursorPosition();
};

#endif