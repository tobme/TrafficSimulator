#pragma once

#include "World.h"
#include "DrawableShape.h"

#include "DeploymentMaster.h"
#include "TriggerConnector.h"
#include "MapParser.h"

#include <SFML/Graphics.hpp>

//using namespace factory;
using namespace map;

using namespace base;
using namespace graphics;
using namespace deployment;

int main()
{
	//Deploy
	deployWorld();

	auto& world = World::getInstance();
	

	sf::RenderWindow& window(world.m_renderwindow);

	// Connect
	connectTriggers();

	while (window.isOpen())
	{
		auto& drawItems = world.m_drawingItems;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (const DrawableShape* item : drawItems)
		{
			if (item != nullptr)
			item->draw(window);
		}
		window.display();
	}

	return 0;
}
