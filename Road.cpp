#pragma once

#include "Road.h"

#include "TextureId.h"

using namespace base;
using namespace object;

namespace road {

	unsigned int VerticalRoad::index(1);

	VerticalRoad::VerticalRoad(const std::string& name, Subscriber* pSubcriber, const sf::Vector2f& pos)
		: WalkableRectangleProp(name + std::to_string(index++), VerticalRoadId, pos, 0)
	{

	}
	VerticalRoad::~VerticalRoad()
	{}
}