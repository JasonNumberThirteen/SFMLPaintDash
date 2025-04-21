#include "../headers/constants.hpp"
#include "../headers/gameApplication.hpp"

#include <SFML/Graphics.hpp>

auto gameApplication = PaintDash::core::GameApplication(sf::VideoMode({PaintDash::constants::GAME_WIDTH, PaintDash::constants::GAME_HEIGHT}), PaintDash::constants::GAME_TITLE, sf::Style::Default, sf::State::Windowed);

int main()
{
	gameApplication.init();

	return 0;
}