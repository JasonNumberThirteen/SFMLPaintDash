#ifndef PAINT_DASH_GAME_APPLICATION_H
#define PAINT_DASH_GAME_APPLICATION_H

#include <SFML/Graphics.hpp>

#include "sprite.hpp"
#include "managers/sceneManager.hpp"
#include "managers/spriteManager.hpp"
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
		GameApplication(sf::VideoMode videoMode, const sf::String& title, uint32_t style, sf::State state);
		void init();
		const sf::RenderWindow& getWindow();
		const sf::Font& getFont();
		const PaintDash::managers::TextureManager& getTextureManager();
		const PaintDash::managers::SpriteManager& getSpriteManager();
	private:
		sf::RenderWindow window;
		sf::Font gameFont;
		PaintDash::managers::TextureManager textureManager = PaintDash::managers::TextureManager();
		PaintDash::managers::SpriteManager spriteManager = PaintDash::managers::SpriteManager();
		PaintDash::managers::SceneManager sceneManager = PaintDash::managers::SceneManager();
		void update();
		void draw();
		void updateCursorPosition();
};

#endif