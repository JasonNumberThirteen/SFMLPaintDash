#include <memory>
#include <algorithm>

#include "../../headers/scene/mainMenuScene.hpp"
#include "../../headers/managers/sceneManager.hpp"

PaintDash::managers::SceneManager::SceneManager()
{
	auto mainMenuScene = PaintDash::scenes::MainMenuScene();
	
	scenes.push_back(std::make_shared<PaintDash::scenes::MainMenuScene>(mainMenuScene));
}

void PaintDash::managers::SceneManager::changeScene(std::string id)
{
	auto sceneWithID = getSceneByKey(id);

	if(sceneWithID == nullptr)
	{
		return;
	}

	currentScene = sceneWithID;

	if(currentScene != nullptr)
	{
		currentScene->init();
	}
}

void PaintDash::managers::SceneManager::init()
{
	changeScene("MAIN_MENU");
}

void PaintDash::managers::SceneManager::update()
{
	if(currentScene != nullptr)
	{
		currentScene->update();
	}
}

void PaintDash::managers::SceneManager::processInput(std::optional<sf::Event> event)
{
	if(currentScene != nullptr)
	{
		currentScene->processInput(event);
	}
}

void PaintDash::managers::SceneManager::draw(sf::RenderWindow& window)
{
	if(currentScene != nullptr)
	{
		currentScene->draw(window);
	}
}

std::shared_ptr<PaintDash::core::Scene> PaintDash::managers::SceneManager::getSceneByKey(const std::string& id)
{
	auto iterator = std::find_if(scenes.begin(), scenes.end(), [=](const std::shared_ptr<PaintDash::core::Scene>& scene)
	{
		return scene->getID().compare(id) == 0;
	});

	return *iterator;
}