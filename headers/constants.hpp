#ifndef PAINT_DASH_CONSTANTS_H
#define PAINT_DASH_CONSTANTS_H

#include <SFML/Graphics.hpp>

namespace PaintDash
{
	namespace constants
	{
		extern const unsigned int GAME_WIDTH;
		extern const unsigned int GAME_HEIGHT;
		extern const unsigned int GAME_FRAMERATE_LIMIT;
		extern const char* GAME_TITLE;
		extern const sf::Color BACKGROUND_COLOR;
		
		namespace textureKeys
		{
			extern const char* CURSOR_TEXTURE_KEY;
			extern const char* GAME_LOGO_TEXTURE_KEY;
		}
	}
}

#endif