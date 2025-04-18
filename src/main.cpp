#include "sprite.hpp"
#include "textUI.hpp"
#include "constants.hpp"
#include "scenes/mainMenuScene.hpp"

#include <SFML/Graphics.hpp>

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode({constants::GAME_WIDTH, constants::GAME_HEIGHT}), constants::GAME_TITLE, sf::Style::Default, sf::State::Windowed);
	auto gameFont = sf::Font("assets/fonts/nationalPark.ttf");
	auto cursorSprite = PaintDash::graphics::Sprite("assets/images/cursor.png");
	auto mainMenuScene = PaintDash::scenes::MainMenuScene(window, gameFont);

	window.setFramerateLimit(144);
	window.setMouseCursorVisible(false);
	mainMenuScene.init();

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if(event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if(const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
			{
				if(!mainMenuScene.anyKeyWasPressed())
				{
					mainMenuScene.setPressedAnyKey(true);
				}
			}
			else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if(!mainMenuScene.anyKeyWasPressed())
				{
					mainMenuScene.setPressedAnyKey(true);
				}
			}
		}

		auto mousePosition = sf::Mouse::getPosition(window);

		cursorSprite.getSprite().setPosition(static_cast<sf::Vector2f>(mousePosition));
		mainMenuScene.draw(window);
		window.draw(cursorSprite.getSprite());
		window.display();
	}
}