
#pragma once

#include "DrawableShape.h"
#include "IObject.h"
#include "Subscriber.h"
#include "Map.h"
#include "IConfig.h"

#include <string>
#include <unordered_map>
#include <thread> 

namespace base {

	class World
	{
	public:
		World(World const&) = delete;
		~World() = default;

		void operator=(World const&) = delete;

		static World& getInstance();
		void init();
		template<typename T>
		static T* getItem(const std::string& name);

		std::unordered_map<std::string, std::unique_ptr<base::IObject>> m_items;
		std::vector<const graphics::DrawableShape*> m_drawingItems;
		std::thread m_drawingThread;
		sf::RenderWindow m_renderwindow;
		base::Subscriber m_subscriber;
		::map::Map m_map;
	private:
		World();

	};

	void addItem(const std::string& name, std::unique_ptr<base::IObject> object, bool add);

	template<typename T>
	static inline T* World::getItem(const std::string& name)
	{
		auto& world = World::getInstance();
		return dynamic_cast<T*>(world.m_items[name].get());
	}

}

