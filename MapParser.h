#pragma once

#include "Map.h"
#include "Subscriber.h"

#include<vector>
#include<fstream>
#include<iostream>

namespace map {
	class MapParser
	{
	public:

		MapParser(const std::string& configName, base::Subscriber* pSubscriber);
		~MapParser();

		const Map& getMap() const;
	private:

		template <typename T>
		void addMapItem(unsigned int x, unsigned int y, T mapItem);

		void addTaxi(const std::string& name, base::Subscriber* pSubscriber, unsigned int x, unsigned int y);
		void addVerticalRoad(const std::string& name, base::Subscriber* pSubscriber, unsigned int x, unsigned int y);
		void addGrass(const std::string& name, unsigned int x, unsigned int y);

		std::ifstream getMapStream(const std::string& configName) const;

		Map m_map;
	};


	template<typename T>
	inline void MapParser::addMapItem(unsigned int x, unsigned int y, T mapItem)
	{
		m_map.add<T>(x, y, mapItem);
	}
}