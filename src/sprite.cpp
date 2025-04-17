#include "sprite.hpp"

PaintDash::graphics::Sprite::Sprite(const std::string &filename) : sprite(texture)
{
	texture = sf::Texture(filename);
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