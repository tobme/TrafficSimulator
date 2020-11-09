#pragma once

#include "Grass.h"

namespace factory {
	shapes::Grass* createGrass(const std::string& name, const sf::Vector2f& pos);
}