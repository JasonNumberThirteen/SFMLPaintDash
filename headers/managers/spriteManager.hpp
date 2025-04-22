#ifndef PAINT_DASH_SPRITE_MANAGER_H
#define PAINT_DASH_SPRITE_MANAGER_H

#include <unordered_map>

#include "../sprite.hpp"

namespace PaintDash
{
	namespace managers
	{
		class SpriteManager;
	}
}

class PaintDash::managers::SpriteManager
{
	public:
		SpriteManager();
		~SpriteManager();
		void addSprite(const std::string key);
		PaintDash::graphics::Sprite& getSpriteByKey(const std::string key) const;
	private:
		std::unordered_map<std::string, PaintDash::graphics::Sprite*> sprites;
};

#endif