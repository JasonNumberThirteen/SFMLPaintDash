#include "../headers/textUI.hpp"

PaintDash::graphics::TextUI::TextUI(const sf::Font& font, const std::string string, unsigned int characterSize) : sf::Text(font, string, characterSize)
{
	
}

void PaintDash::graphics::TextUI::setCenteredPosition(sf::Vector2f position)
{
	auto textRect = getLocalBounds();

	setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x*0.5f, textRect.position.y + textRect.size.y*0.5f));
	setPosition(position);
}