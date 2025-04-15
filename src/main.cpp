#include "constants.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode({constants::GAME_WIDTH, constants::GAME_HEIGHT}), constants::GAME_TITLE, sf::Style::Default, sf::State::Windowed);
	auto windowSize = window.getSize();
	auto gameFont = sf::Font("assets/fonts/nationalPark.ttf");
	auto pressAnyKeyText = sf::Text(gameFont);
	auto gameLogoTexture = sf::Texture("assets/images/mainMenu/gameLogo.png");
	auto cursorTexture = sf::Texture("assets/images/cursor.png");
	auto gameLogoTextureSize = gameLogoTexture.getSize();
	auto gameLogoSprite = sf::Sprite(gameLogoTexture);
	auto cursorSprite = sf::Sprite(cursorTexture);

	window.setFramerateLimit(144);
	window.setMouseCursorVisible(false);
	gameLogoSprite.setPosition(sf::Vector2f((windowSize.x - gameLogoTextureSize.x) >> 1, (windowSize.y - gameLogoTextureSize.y) >> 1));
	pressAnyKeyText.setString("Press any key");
	pressAnyKeyText.setCharacterSize(32);

	auto pressAnyKeyTextRect = pressAnyKeyText.getLocalBounds();

	pressAnyKeyText.setOrigin(sf::Vector2f(pressAnyKeyTextRect.position.x + pressAnyKeyTextRect.size.x*0.5f, pressAnyKeyTextRect.position.y + pressAnyKeyTextRect.size.y*0.5f));
	pressAnyKeyText.setPosition(sf::Vector2f(windowSize.x*0.5f, (windowSize.y + gameLogoTextureSize.y)*0.5f + 64));

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
		window.draw(pressAnyKeyText);
		window.draw(cursorSprite);
		window.display();
	}
}