#include "../../headers/scene/scene.hpp"

PaintDash::core::Scene::Scene(const std::string id)
{
	this->id = id;
}

const std::string& PaintDash::core::Scene::getID()
{
	return id;
}