#include "../headers/constants.hpp"
#include "../headers/gameApplication.hpp"

extern PaintDash::core::GameApplication gameApplication;

PaintDash::core::GameApplication::GameApplication(sf::VideoMode videoMode, const sf::String &title, uint32_t style, sf::State state) : window(sf::RenderWindow(videoMode, title, style, state))
{
	gameFont = sf::Font("assets/fonts/nationalPark.ttf");
}

void PaintDash::core::GameApplication::init()
{
	window.setFramerateLimit(PaintDash::constants::GAME_FRAMERATE_LIMIT);
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

const PaintDash::managers::SpriteManager& PaintDash::core::GameApplication::getSpriteManager()
{
	return spriteManager;
}

const PaintDash::managers::SceneManager& PaintDash::core::GameApplication::getSceneManager()
{
	return sceneManager;
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

	spriteManager.getSpriteByKey(PaintDash::constants::textureKeys::CURSOR_TEXTURE_KEY).getSprite().setPosition(static_cast<sf::Vector2f>(mousePosition));
}

void PaintDash::core::GameApplication::draw()
{
	sceneManager.draw(window);
	window.draw(spriteManager.getSpriteByKey(PaintDash::constants::textureKeys::CURSOR_TEXTURE_KEY).getSprite());
}