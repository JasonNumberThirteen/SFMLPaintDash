#include "constants.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode({constants::GAME_WIDTH, constants::GAME_HEIGHT}), constants::GAME_TITLE, sf::Style::Default, sf::State::Windowed);
	auto gameLogoTexture = sf::Texture("assets/images/mainMenu/gameLogo.png");
	auto gameLogoSprite = sf::Sprite(gameLogoTexture);

	window.setFramerateLimit(144);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if(event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		window.clear(constants::BACKGROUND_COLOR);
		window.draw(gameLogoSprite);
		window.display();
	}
}