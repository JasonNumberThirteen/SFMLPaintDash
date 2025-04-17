#include "sprite.hpp"
#include "textUI.hpp"
#include "constants.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode({constants::GAME_WIDTH, constants::GAME_HEIGHT}), constants::GAME_TITLE, sf::Style::Default, sf::State::Windowed);
	auto windowSize = window.getSize();
	auto gameFont = sf::Font("assets/fonts/nationalPark.ttf");
	auto pressAnyKeyText = PaintDash::graphics::TextUI(gameFont, "Press any key", 32);
	auto gameLogoSprite = PaintDash::graphics::Sprite("assets/images/mainMenu/gameLogo.png");
	auto gameLogoTextureSize = gameLogoSprite.getSize();
	auto cursorSprite = PaintDash::graphics::Sprite("assets/images/cursor.png");
	auto pressedAnyKey = false;

	window.setFramerateLimit(144);
	window.setMouseCursorVisible(false);
	gameLogoSprite.getSprite().setPosition(sf::Vector2f((windowSize.x - gameLogoTextureSize.x) >> 1, (windowSize.y - gameLogoTextureSize.y) >> 1));
	pressAnyKeyText.setCenteredPosition(sf::Vector2f(windowSize.x*0.5f, (windowSize.y + gameLogoTextureSize.y)*0.5f + 64));

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
				if(!pressedAnyKey)
				{
					pressedAnyKey = true;
				}
			}
			else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if(!pressedAnyKey)
				{
					pressedAnyKey = true;
				}
			}
		}

		auto mousePosition = sf::Mouse::getPosition(window);

		cursorSprite.getSprite().setPosition(static_cast<sf::Vector2f>(mousePosition));
		window.clear(constants::BACKGROUND_COLOR);
		window.draw(gameLogoSprite.getSprite());

		if(!pressedAnyKey)
		{
			window.draw(pressAnyKeyText);
		}

		window.draw(cursorSprite.getSprite());
		window.display();
	}
}