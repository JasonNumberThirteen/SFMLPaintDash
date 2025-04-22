#include "../headers/constants.hpp"
#include "../headers/gameApplication.hpp"

#include <SFML/Graphics.hpp>

using namespace PaintDash;

auto gameApplication = core::GameApplication(sf::VideoMode({constants::GAME_WIDTH, constants::GAME_HEIGHT}), constants::GAME_TITLE, sf::Style::Default, sf::State::Windowed);

int main()
{
	gameApplication.init();

	return 0;
}