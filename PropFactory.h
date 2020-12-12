#pragma once

#include "Grass.h"

namespace factory {
	std::unique_ptr<shapes::Grass> createGrass(const std::string& name, const sf::Vector2f& pos);
}