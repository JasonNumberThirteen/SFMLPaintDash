#ifndef PAINT_DASH_SCENE_MANAGER_H
#define PAINT_DASH_SCENE_MANAGER_H

#include "../scenes/scene.hpp"

namespace PaintDash
{
	namespace managers
	{
		class SceneManager;
	}
}

class PaintDash::managers::SceneManager
{
	public:
		SceneManager();
		void changeScene(std::string id);
		void init();
		void update(float deltaTime);
		void processInput(std::optional<sf::Event> event);
		void draw(sf::RenderWindow& window);
		std::shared_ptr<PaintDash::core::Scene> getSceneByKey(const std::string& id);
	private:
		std::vector<std::shared_ptr<PaintDash::core::Scene>> scenes;
		std::shared_ptr<PaintDash::core::Scene> currentScene;
};

#endif