#include "../../headers/constants.hpp"
#include "../../headers/gameApplication.hpp"
#include "../../headers/scenes/mainMenuScene.hpp"

extern PaintDash::core::GameApplication gameApplication;

PaintDash::scenes::MainMenuScene::MainMenuScene() : Scene("MAIN_MENU")
{
	
}

void PaintDash::scenes::MainMenuScene::init()
{
	mainMenuPanelUI.init();
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

void PaintDash::scenes::MainMenuScene::draw(sf::RenderWindow& window)
{
	window.clear(PaintDash::constants::BACKGROUND_COLOR);
	mainMenuPanelUI.draw(window);
}

void PaintDash::scenes::MainMenuScene::setKeyAsPressedIfNeeded()
{
	if(pressedAnyKey)
	{
		return;
	}

	pressedAnyKey = true;

	if(pressedAnyKeyEvent != nullptr)
	{
		pressedAnyKeyEvent();
	}
}

bool PaintDash::scenes::MainMenuScene::anyKeyWasPressed()
{
	return pressedAnyKey;
}