#ifndef PAINT_DASH_MAIN_MENU_SCENE_H
#define PAINT_DASH_MAIN_MENU_SCENE_H

#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "../sprite.hpp"
#include "../textUI.hpp"

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
		MainMenuScene();
		void init() override;
		void update() override;
		void processInput(std::optional<sf::Event> event) override;
		void draw(sf::RenderWindow& window) override;
		void setKeyAsPressedIfNeeded();
	private:
		bool pressedAnyKey = false;
		PaintDash::graphics::TextUI pressAnyKeyText;
		sf::Vector2u windowSize;
};

#endif