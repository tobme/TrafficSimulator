#include "World.h"

#include "IObject.h"
#include "MapFactory.h"
#include "MapParser.h"

#include <SFML/System.hpp>

using namespace map;

namespace base {

	using namespace graphics;

	World& World::getInstance()
	{
		static World instance;

		return instance;
	}

	void func(std::vector<const DrawableShape*> itemVector)
	{
		auto& instance = World::getInstance();
		while (true)
		{
			for (const DrawableShape* item : itemVector)
			{
				item->draw(instance.m_renderwindow);
			}
			sf::sleep(sf::milliseconds(100));
		}
	}

	void World::init()
	{
		auto& instance = World::getInstance();
		instance.m_renderwindow.create(sf::VideoMode(1600, 900), "Traffic Simulator");
		//auto config = instance.m_spConfig;

		auto mapParser = MapParser("Maps/Config.txt", &instance.m_subscriber);
		instance.m_map = mapParser.getMap();

		auto& drawingItems = instance.m_drawingItems;
		std::sort(drawingItems.begin(), drawingItems.end(), [](const DrawableShape* lhs, const DrawableShape* rhs)
			{
				return lhs > rhs;
			});

		//config->setMap(mapParser.getMap());

		//sf::Thread thread(std::bind(&func, instance.m_drawingItems));
		//thread.launch();
	}

	World::World()
		: m_items()
		, m_drawingItems()
		, m_renderwindow()
		, m_map()
	{
	}

	void addItem(const std::string& name, IObject* object, bool add)
	{
		if (add)
		{
			auto& world = World::getInstance();
			world.m_items[name] = std::unique_ptr<IObject>(object);

			if (auto it = dynamic_cast<const DrawableShape*>(object))
			{
				world.m_drawingItems.push_back(it);

				std::sort(world.m_drawingItems.begin(), world.m_drawingItems.end(), [](const DrawableShape * lhs, const DrawableShape * rhs)
					{
						return lhs > rhs;
					});
			}
		}

	}
}
