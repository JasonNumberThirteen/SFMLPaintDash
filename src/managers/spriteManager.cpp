#include "../../headers/constants.hpp"
#include "../../headers/gameApplication.hpp"
#include "../../headers/managers/spriteManager.hpp"

extern PaintDash::core::GameApplication gameApplication;

PaintDash::managers::SpriteManager::SpriteManager()
{
	addSprite(PaintDash::constants::textureKeys::CURSOR_TEXTURE_KEY);
	addSprite(PaintDash::constants::textureKeys::GAME_LOGO_TEXTURE_KEY);
}

PaintDash::managers::SpriteManager::~SpriteManager()
{
	PaintDash::graphics::Sprite *currentSprite;
	auto iterator = sprites.begin();

	while (iterator != sprites.end())
	{
		currentSprite = iterator->second;
		delete currentSprite;
		++iterator;
	}
}

void PaintDash::managers::SpriteManager::addSprite(const std::string key)
{
	auto sprite = new PaintDash::graphics::Sprite(key);

	sprites.insert({key, sprite});
}

PaintDash::graphics::Sprite& PaintDash::managers::SpriteManager::getSpriteByKey(const std::string key) const
{
	return *sprites.at(key);
}