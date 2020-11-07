#include "MapParser.h"

#include "Taxi.h"
#include "World.h"

// Factories
#include "CarFactory.h"
#include "RoadFactory.h"

using namespace shape::cars;
using namespace base;
using namespace std;
using namespace factory;
using namespace road;

namespace map {

	void MapParser::addTaxi(const std::string& name, Subscriber* pSubscriber, unsigned int x, unsigned int y)
	{
		// Also create road for the pos
		auto pRoad = createVerticalRoad(name, pSubscriber, sf::Vector2f(PROP_SIZE * x, PROP_SIZE * y));
		addItem(pRoad->getName(), pRoad, true);

		Taxi* pTaxi = createTaxi(name, pSubscriber, sf::Vector2f(100 * x, 50 * y));
		addItem(pTaxi->getName(), pTaxi, true);

		addMapItem<VerticalRoad*>(x, y, pRoad);
	}

	void MapParser::addVerticalRoad(const std::string& name, Subscriber* pSubscriber, unsigned int x, unsigned int y)
	{
		auto pRoad = createVerticalRoad(name, pSubscriber, sf::Vector2f(PROP_SIZE * x, PROP_SIZE * y));
		addItem(pRoad->getName(), pRoad, true);

		addMapItem<VerticalRoad*>(x, y, pRoad);
	}

	MapParser::MapParser(const std::string& configName, Subscriber* pSubscriber)
		: m_map(18, 32)
	{
		ifstream mapFile = getMapStream(configName);

		//! @todo Change to json format
		int objectNumber;
		int taxiIndex(0);
		int roadIndex(0);
		std::string name;

		unsigned int x(0);
		unsigned int y(0);
		while (mapFile >> objectNumber)
		{
			switch (objectNumber)
			{
			case 1:
				//Road
				addVerticalRoad("VerticalRoad", pSubscriber, x, y);
				break;
			case 2:
				//Taxi
				addTaxi("Taxi", pSubscriber, x, y);
				break;
			default:
				// Not implemented
				break;
			}
			++x;
			if (mapFile.peek() == '\n')
			{
				x = 0;
				y++;
			}
		}
	}

	ifstream MapParser::getMapStream(const std::string& configName) const
	{
		ifstream configFile(configName);
		std::string mapName;
		if (configFile.is_open())
		{
			configFile >> mapName;

			ifstream mapFile(mapName);

			if (mapFile.is_open())
			{
				return mapFile;
			}
		}
		// THROW EXCEPTION
		return configFile;
	}

	MapParser::~MapParser()
	{
	}

	const Map& MapParser::getMap() const
	{
		return m_map;
	}
}