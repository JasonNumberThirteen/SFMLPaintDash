#include "../headers/gameApplication.hpp"
#include "../headers/managers/textureManager.hpp"

extern PaintDash::core::GameApplication gameApplication;

PaintDash::core::GameApplication::GameApplication(sf::VideoMode videoMode, const sf::String &title, uint32_t style, sf::State state) : window(sf::RenderWindow(videoMode, title, style, state)), cursorSprite("cursor"), gameLogoSprite("gameLogo")
{
	gameFont = sf::Font("assets/fonts/nationalPark.ttf");
}

void PaintDash::core::GameApplication::init()
{
	window.setFramerateLimit(144);
	window.setMouseCursorVisible(false);
	sceneManager.init();

	while (window.isOpen())
	{
		update();
		draw();
		window.display();
	}
}

const sf::RenderWindow& PaintDash::core::GameApplication::getWindow()
{
	return window;
}

const sf::Font& PaintDash::core::GameApplication::getFont()
{
	return gameFont;
}

const PaintDash::managers::TextureManager& PaintDash::core::GameApplication::getTextureManager()
{
	return textureManager;
}

void PaintDash::core::GameApplication::update()
{
	while (const std::optional event = window.pollEvent())
	{
		if(event->is<sf::Event::Closed>())
		{
			window.close();
		}

		sceneManager.processInput(event);
	}

	updateCursorPosition();
}

void PaintDash::core::GameApplication::updateCursorPosition()
{
	auto mousePosition = sf::Mouse::getPosition(window);

	cursorSprite.getSprite().setPosition(static_cast<sf::Vector2f>(mousePosition));
}

void PaintDash::core::GameApplication::draw()
{
	sceneManager.draw(window);
	window.draw(cursorSprite.getSprite());
}

PaintDash::graphics::Sprite& PaintDash::core::GameApplication::getGameLogoSprite()
{
	return gameLogoSprite;
}