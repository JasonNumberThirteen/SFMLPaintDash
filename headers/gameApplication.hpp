#ifndef PAINT_DASH_GAME_APPLICATION_H
#define PAINT_DASH_GAME_APPLICATION_H

#include <SFML/Graphics.hpp>

#include "sprite.hpp"
#include "managers/sceneManager.hpp"
#include "managers/textureManager.hpp"

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
		sf::RenderWindow& getWindow();
		sf::Font& getFont();
		PaintDash::managers::TextureManager& getTextureManager();
		PaintDash::graphics::Sprite& getGameLogoSprite();
	private:
		sf::RenderWindow window;
		sf::Font gameFont;
		PaintDash::managers::TextureManager textureManager = PaintDash::managers::TextureManager();
		PaintDash::managers::SceneManager sceneManager = PaintDash::managers::SceneManager();
		PaintDash::graphics::Sprite cursorSprite;
		PaintDash::graphics::Sprite gameLogoSprite;
		void update();
		void draw();
		void updateCursorPosition();
};

#endif