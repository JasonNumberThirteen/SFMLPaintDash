#ifndef PAINT_DASH_MAIN_MENU_PANEL_UI
#define PAINT_DASH_MAIN_MENU_PANEL_UI

#include "../ui/textUI.hpp"

namespace PaintDash
{
	namespace graphics
	{
		class MainMenuPanelUI;
	}
}

class PaintDash::graphics::MainMenuPanelUI
{
	public:
		MainMenuPanelUI();
		void init();
		void update(float deltaTime);
		void draw(sf::RenderWindow& window);
	private:
		sf::Vector2u windowSize;
		PaintDash::graphics::TextUI pressAnyKeyText;
		bool pressedAnyKey = false;
		float gameLogoSpriteInitialY;
};

#endif