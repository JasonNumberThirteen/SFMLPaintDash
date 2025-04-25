#ifndef PAINT_DASH_MAIN_MENU_SCENE_H
#define PAINT_DASH_MAIN_MENU_SCENE_H

#include <functional>
#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "../ui/mainMenuPanelUI.hpp"

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
		std::function<void()> pressedAnyKeyEvent;
		MainMenuScene();
		void init() override;
		void update(float deltaTime) override;
		void processInput(std::optional<sf::Event> event) override;
		void draw(sf::RenderWindow& window) override;
		void setKeyAsPressedIfNeeded();
		bool anyKeyWasPressed();
	private:
		bool pressedAnyKey = false;
		PaintDash::graphics::MainMenuPanelUI mainMenuPanelUI;
};

#endif