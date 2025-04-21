#include "../../headers/scene/scene.hpp"

PaintDash::core::Scene::Scene(const std::string id)
{
	this->id = id;
}

std::string PaintDash::core::Scene::getID() const
{
	return id;
}