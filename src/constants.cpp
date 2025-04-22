#include <SFML/Graphics.hpp>

#include "../headers/constants.hpp"

namespace PaintDash
{
	namespace constants
	{
		const unsigned int GAME_WIDTH = 1280U;
		const unsigned int GAME_HEIGHT = 720U;
		const unsigned int GAME_FRAMERATE_LIMIT = 144U;
		const char* GAME_TITLE = "Paint Dash";
		const sf::Color BACKGROUND_COLOR = sf::Color(108, 199, 230);
		
		namespace textureKeys
		{
			const char* CURSOR_TEXTURE_KEY = "cursor";
			const char* GAME_LOGO_TEXTURE_KEY = "gameLogo";
		}
	}
}