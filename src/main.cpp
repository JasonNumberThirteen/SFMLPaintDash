#include "constants.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode({constants::GAME_WIDTH, constants::GAME_HEIGHT}), constants::GAME_TITLE, sf::Style::Default, sf::State::Windowed);
	auto windowSize = window.getSize();
	auto gameLogoTexture = sf::Texture("assets/images/mainMenu/gameLogo.png");
	auto cursorTexture = sf::Texture("assets/images/cursor.png");
	auto gameLogoTextureSize = gameLogoTexture.getSize();
	auto gameLogoSprite = sf::Sprite(gameLogoTexture);
	auto cursorSprite = sf::Sprite(cursorTexture);

	window.setFramerateLimit(144);
	window.setMouseCursorVisible(false);
	gameLogoSprite.setPosition(sf::Vector2f((windowSize.x - gameLogoTextureSize.x) >> 1, (windowSize.y - gameLogoTextureSize.y) >> 1));

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if(event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		auto mousePosition = sf::Mouse::getPosition(window);

		cursorSprite.setPosition(static_cast<sf::Vector2f>(mousePosition));
		window.clear(constants::BACKGROUND_COLOR);
		window.draw(gameLogoSprite);
		window.draw(cursorSprite);
		window.display();
	}
}