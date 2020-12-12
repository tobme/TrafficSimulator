#include "MapParser.h"

#include "Taxi.h"
#include "World.h"

// Factories
#include "CarFactory.h"
#include "RoadFactory.h"
#include "PropFactory.h"

using namespace shapes;
using namespace shape::cars;
using namespace base;
using namespace std;
using namespace factory;
using namespace road;

namespace map {

	void MapParser::addTaxi(const std::string& name, Subscriber* pSubscriber, unsigned int x, unsigned int y)
	{
		// Also create road for the pos
		auto pRoad(createVerticalRoad(name, pSubscriber, sf::Vector2f(PROP_SIZE * x, PROP_SIZE * y)));
		std::string roadName(pRoad->getName());
		addMapItem<VerticalRoad*>(x, y, pRoad.get());
		addItem(roadName, std::move(pRoad), true);

		auto pTaxi(createTaxi(name, pSubscriber, sf::Vector2f(50 * x, 50 * y)));
		std::string taxiName(pTaxi->getName());
		addItem(taxiName, std::move(pTaxi), true);
	}

	void MapParser::addVerticalRoad(const std::string& name, Subscriber* pSubscriber, unsigned int x, unsigned int y)
	{
		auto pRoad(createVerticalRoad(name, pSubscriber, sf::Vector2f(PROP_SIZE * x, PROP_SIZE * y)));
		
		std::string roadName(pRoad->getName());
		addMapItem<VerticalRoad*>(x, y, pRoad.get());
		addItem(roadName, std::move(pRoad), true);
	}

	void MapParser::addGrass(const std::string& name, unsigned int x, unsigned int y)
	{
		auto pGrass(createGrass(name, sf::Vector2f(PROP_SIZE * x, PROP_SIZE * y)));
	
		addMapItem<Grass*>(x, y, pGrass.get());
		std::string grassName(pGrass->getName());
		addItem(grassName, std::move(pGrass), true);
	}

	MapParser::MapParser(const std::string& configName, Subscriber* pSubscriber)
		: m_map(16, 18)
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
			case 0:
				addGrass("Grass", x, y);
				break;
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