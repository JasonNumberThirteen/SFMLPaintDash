#ifndef PAINT_DASH_MAIN_MENU_SCENE_H
#define PAINT_DASH_MAIN_MENU_SCENE_H

#include <SFML/Graphics.hpp>

#include "../sprite.hpp"
#include "../textUI.hpp"
#include "scene.hpp"

namespace PaintDash
{
	namespace scenes
	{
		class MainMenuScene;
	}
}

class PaintDash::scenes::MainMenuScene : public PaintDash::core::Scene
{
	public:
		MainMenuScene(sf::RenderWindow &window, const sf::Font &font);
		void init();
		void update();
		void draw(sf::RenderWindow &window);
		bool anyKeyWasPressed();
		void setPressedAnyKey(bool pressed);
	private:
		bool pressedAnyKey = false;
		PaintDash::graphics::Sprite gameLogoSprite;
		PaintDash::graphics::TextUI pressAnyKeyText;
		sf::Vector2u windowSize;
};

#endif