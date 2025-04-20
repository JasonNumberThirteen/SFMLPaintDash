#include "../../headers/sprite.hpp"
#include "../../headers/textUI.hpp"
#include "../../headers/constants.hpp"
#include "../../headers/scene/mainMenuScene.hpp"
#include "../../headers/managers/textureManager.hpp"

PaintDash::scenes::MainMenuScene::MainMenuScene(sf::RenderWindow &window, const sf::Font &font) : Scene("MAIN_MENU"), pressAnyKeyText(font, "Press any key", 32), gameLogoSprite("gameLogo")
{
	windowSize = window.getSize();
}

void PaintDash::scenes::MainMenuScene::init()
{
	auto gameLogoTextureSize = gameLogoSprite.getSize();

	gameLogoSprite.getSprite().setPosition(sf::Vector2f((windowSize.x - gameLogoTextureSize.x) >> 1, (windowSize.y - gameLogoTextureSize.y) >> 1));
	pressAnyKeyText.setCenteredPosition(sf::Vector2f(windowSize.x*0.5f, (windowSize.y + gameLogoTextureSize.y)*0.5f + 64));
}

void PaintDash::scenes::MainMenuScene::update()
{
	
}

void PaintDash::scenes::MainMenuScene::draw(sf::RenderWindow &window)
{
	window.clear(PaintDash::constants::BACKGROUND_COLOR);
	window.draw(gameLogoSprite.getSprite());

	if(!pressedAnyKey)
	{
		window.draw(pressAnyKeyText);
	}
}

bool PaintDash::scenes::MainMenuScene::anyKeyWasPressed()
{
	return pressedAnyKey;
}

void PaintDash::scenes::MainMenuScene::setPressedAnyKey(bool pressed)
{
	pressedAnyKey = pressed;
}