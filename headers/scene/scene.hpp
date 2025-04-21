#ifndef PAINT_DASH_SCENE_H
#define PAINT_DASH_SCENE_H

#include <SFML/Graphics.hpp>

namespace PaintDash
{
	namespace core
	{
		class Scene;
	}
}

class PaintDash::core::Scene
{
	public:
		Scene(const std::string id);
		virtual void init() = 0;
		virtual void update() = 0;
		virtual void processInput(std::optional<sf::Event> event) = 0;
		virtual void draw(sf::RenderWindow &window) = 0;
		std::string getID() const;
	private:
		std::string id;
};

#endif