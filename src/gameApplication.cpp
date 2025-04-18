#include "../headers/gameApplication.hpp"

PaintDash::core::GameApplication::GameApplication(sf::VideoMode videoMode, const sf::String &title, uint32_t style, sf::State state) : window(sf::RenderWindow(videoMode, title, style, state)), cursorSprite("assets/images/cursor.png"), mainMenuScene(window, gameFont)
{
	gameFont = sf::Font("assets/fonts/nationalPark.ttf");
}

void PaintDash::core::GameApplication::init()
{
	window.setFramerateLimit(144);
	window.setMouseCursorVisible(false);
	mainMenuScene.init();

	while (window.isOpen())
	{
		update();
		draw();
		window.display();
	}
}

void PaintDash::core::GameApplication::update()
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

	updateCursorPosition();
}

void PaintDash::core::GameApplication::draw()
{
	mainMenuScene.draw(window);
	window.draw(cursorSprite.getSprite());
}

void PaintDash::core::GameApplication::updateCursorPosition()
{
	auto mousePosition = sf::Mouse::getPosition(window);

	cursorSprite.getSprite().setPosition(static_cast<sf::Vector2f>(mousePosition));
}