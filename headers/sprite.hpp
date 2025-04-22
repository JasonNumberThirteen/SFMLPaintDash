#ifndef PAINT_DASH_SPRITE_H
#define PAINT_DASH_SPRITE_H

#include <SFML/Graphics.hpp>

namespace PaintDash
{
	namespace graphics
	{
		class Sprite;
	}
}

class PaintDash::graphics::Sprite
{
	public:
		Sprite(const std::string& textureKey);
		sf::Vector2u getSize();
		sf::Sprite& getSprite();
	private:
		sf::Texture texture;
		sf::Sprite sprite;
};

#endif