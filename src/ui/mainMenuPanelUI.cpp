#include "../../headers/constants.hpp"
#include "../../headers/gameApplication.hpp"
#include "../../headers/ui/mainMenuPanelUI.hpp"
#include "../../headers/scenes/mainMenuScene.hpp"

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
			gameLogoSprite.getSprite().move(sf::Vector2f(0, -160));
			
			pressedAnyKey = true;
		};
	}
	
	gameLogoSprite.getSprite().setPosition(sf::Vector2f((windowSize.x - gameLogoTextureSize.x) >> 1, (windowSize.y - gameLogoTextureSize.y) >> 1));
	pressAnyKeyText.setCenteredPosition(sf::Vector2f(windowSize.x*0.5f, (windowSize.y + gameLogoTextureSize.y)*0.5f + 64));
}

void PaintDash::graphics::MainMenuPanelUI::draw(sf::RenderWindow& window)
{
	window.draw(gameApplication.getSpriteManager().getSpriteByKey(PaintDash::constants::textureKeys::GAME_LOGO_TEXTURE_KEY).getSprite());

	if(!pressedAnyKey)
	{
		window.draw(pressAnyKeyText);
	}
}