#include "../../headers/constants.hpp"
#include "../../headers/managers/textureManager.hpp"

PaintDash::managers::TextureManager::TextureManager()
{
	addTexture(PaintDash::constants::textureKeys::CURSOR_TEXTURE_KEY, "assets/images/cursor.png");
	addTexture(PaintDash::constants::textureKeys::GAME_LOGO_TEXTURE_KEY, "assets/images/mainMenu/gameLogo.png");
}

PaintDash::managers::TextureManager::~TextureManager()
{
	sf::Texture *currentTexture;
	auto iterator = textures.begin();

	while (iterator != textures.end())
	{
		currentTexture = iterator->second;
		delete currentTexture;
		++iterator;
	}
}

void PaintDash::managers::TextureManager::addTexture(const std::string key, const std::string filename)
{
	auto texture = new sf::Texture();

	if(texture->loadFromFile(filename))
	{
		textures.insert({key, texture});
	}
	else
	{
		delete texture;
	}
}

sf::Texture& PaintDash::managers::TextureManager::getTextureByKey(const std::string key) const
{
	return *textures.at(key);
}