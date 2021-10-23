#pragma once

#include "IEvents.h"

#include <SFML/Graphics.hpp>

namespace event {

	class VehicleCreated : public base::IEvent
	{
	public:
		VehicleCreated(const std::string& name, const sf::Vector2f& pos)
			: IEvent(name, base::EventSpecifier::VEHICLE_CREATED), m_pos(&pos) { }
		~VehicleCreated() {}
		const sf::Vector2f* getPos() const
		{
			return m_pos;
		}
	private:
		const sf::Vector2f* m_pos;
	};
}