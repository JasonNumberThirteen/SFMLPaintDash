#include <SFML/Graphics.hpp>

int main()
{
	const std::string GAME_TITLE = "Paint Dash";

	auto window = sf::RenderWindow(sf::VideoMode({1280u, 720u}), GAME_TITLE, sf::Style::Default, sf::State::Windowed);

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

		window.clear();
		window.display();
	}
}