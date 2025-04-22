#ifndef PAINT_DASH_TEXT_UI_H
#define PAINT_DASH_TEXT_UI_H

#include <SFML/Graphics.hpp>

namespace PaintDash
{
	namespace graphics
	{
		class TextUI;
	}
}

class PaintDash::graphics::TextUI : public sf::Text
{
	public:
		TextUI(const sf::Font& font, const std::string string, unsigned int characterSize);
		void setCenteredPosition(sf::Vector2f position);
};

#endif