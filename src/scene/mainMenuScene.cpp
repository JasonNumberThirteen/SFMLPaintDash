#include "../../headers/constants.hpp"
#include "../../headers/gameApplication.hpp"
#include "../../headers/scene/mainMenuScene.hpp"

extern PaintDash::core::GameApplication gameApplication;

PaintDash::scenes::MainMenuScene::MainMenuScene() : Scene("MAIN_MENU"), pressAnyKeyText(gameApplication.getFont(), "Press any key", 32)
{
	windowSize = gameApplication.getWindow().getSize();
}

void PaintDash::scenes::MainMenuScene::init()
{
	auto gameLogoTextureSize = gameApplication.getGameLogoSprite().getSize();

	gameApplication.getGameLogoSprite().getSprite().setPosition(sf::Vector2f((windowSize.x - gameLogoTextureSize.x) >> 1, (windowSize.y - gameLogoTextureSize.y) >> 1));
	pressAnyKeyText.setCenteredPosition(sf::Vector2f(windowSize.x*0.5f, (windowSize.y + gameLogoTextureSize.y)*0.5f + 64));
}

void PaintDash::scenes::MainMenuScene::update()
{
	
}

void PaintDash::scenes::MainMenuScene::processInput(std::optional<sf::Event> event)
{
	if(const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
	{
		setKeyAsPressedIfNeeded();
	}
	else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
	{
		setKeyAsPressedIfNeeded();
	}
}

void PaintDash::scenes::MainMenuScene::draw(sf::RenderWindow &window)
{
	window.clear(PaintDash::constants::BACKGROUND_COLOR);
	window.draw(gameApplication.getGameLogoSprite().getSprite());

	if(!pressedAnyKey)
	{
		window.draw(pressAnyKeyText);
	}
}

void PaintDash::scenes::MainMenuScene::setKeyAsPressedIfNeeded()
{
	if(!pressedAnyKey)
	{
		pressedAnyKey = true;
	}
}