#include "../headers/sprite.hpp"
#include "../headers/gameApplication.hpp"

extern PaintDash::core::GameApplication gameApplication;

PaintDash::graphics::Sprite::Sprite(const std::string& textureKey) : texture(gameApplication.getTextureManager().getTextureByKey(textureKey)), sprite(texture)
{
	
}

sf::Vector2u PaintDash::graphics::Sprite::getSize()
{
	return texture.getSize();
}

sf::Sprite& PaintDash::graphics::Sprite::getSprite()
{
	return sprite;
}