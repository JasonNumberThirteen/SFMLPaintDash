#include "../../headers/constants.hpp"
#include "../../headers/gameApplication.hpp"
#include "../../headers/ui/mainMenuPanelUI.hpp"
#include "../../headers/scenes/mainMenuScene.hpp"
#include "../../headers/functions/math.hpp"

extern PaintDash::core::GameApplication gameApplication;

PaintDash::graphics::MainMenuPanelUI::MainMenuPanelUI() : pressAnyKeyText(gameApplication.getFont(), "Press any key", 32)
{
	windowSize = gameApplication.getWindow().getSize();
}

void PaintDash::graphics::MainMenuPanelUI::init()
{
	auto sceneManager = gameApplication.getSceneManager();
	auto mainMenuScene = std::dynamic_pointer_cast<PaintDash::scenes::MainMenuScene>(sceneManager.getSceneByKey("MAIN_MENU"));
	auto& gameLogoSprite = gameApplication.getSpriteManager().getSpriteByKey(PaintDash::constants::textureKeys::GAME_LOGO_TEXTURE_KEY);
	auto gameLogoTextureSize = gameLogoSprite.getSize();

	if(mainMenuScene != nullptr)
	{
		mainMenuScene->pressedAnyKeyEvent = [&]
		{
			pressedAnyKey = true;
		};
	}
	
	gameLogoSprite.getSprite().setPosition(sf::Vector2f((windowSize.x - gameLogoTextureSize.x) >> 1, (windowSize.y - gameLogoTextureSize.y) >> 1));
	pressAnyKeyText.setCenteredPosition(sf::Vector2f(windowSize.x*0.5f, (windowSize.y + gameLogoTextureSize.y)*0.5f + 64));

	gameLogoSpriteInitialY = gameLogoSprite.getSprite().getPosition().y;
}

void PaintDash::graphics::MainMenuPanelUI::update(float deltaTime)
{
	auto& gameLogoSprite = gameApplication.getSpriteManager().getSpriteByKey(PaintDash::constants::textureKeys::GAME_LOGO_TEXTURE_KEY);
	auto& gameLogoSpriteSprite = gameLogoSprite.getSprite();
	auto gameLogoSpritePosition = gameLogoSpriteSprite.getPosition();
	auto gameLogoSpriteTargetY = 16;
	
	if(!pressedAnyKey || gameLogoSpritePosition.y <= gameLogoSpriteTargetY)
	{
		return;
	}

	auto gameLogoSpriteY = LERP(gameLogoSpriteInitialY, gameLogoSpriteTargetY, deltaTime);

	gameLogoSpriteSprite.setPosition(sf::Vector2f(gameLogoSpritePosition.x, gameLogoSpriteY));
}

void PaintDash::graphics::MainMenuPanelUI::draw(sf::RenderWindow& window)
{
	window.draw(gameApplication.getSpriteManager().getSpriteByKey(PaintDash::constants::textureKeys::GAME_LOGO_TEXTURE_KEY).getSprite());

	if(!pressedAnyKey)
	{
		window.draw(pressAnyKeyText);
	}
}