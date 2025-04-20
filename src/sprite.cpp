#include "../headers/sprite.hpp"
#include "../headers/managers/textureManager.hpp"

extern PaintDash::managers::TextureManager textureManager;

PaintDash::graphics::Sprite::Sprite(const std::string &textureKey) : sprite(texture)
{
	texture = textureManager.getTextureByKey(textureKey);
	sprite = sf::Sprite(texture);
}

sf::Vector2u PaintDash::graphics::Sprite::getSize()
{
	return texture.getSize();
}

sf::Sprite& PaintDash::graphics::Sprite::getSprite()
{
	return sprite;
}