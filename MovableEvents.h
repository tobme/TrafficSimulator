#pragma once

#include "IEvents.h"
#include "CarStates.h"

#include <SFML/Graphics.hpp>

namespace event {

	class VehicleUpdatedEvent : public base::IEvent
	{
	public:
		VehicleUpdatedEvent(const std::string& name, base::EventSpecifier event)
			: IEvent(name, event), m_event(event)
		{}
		virtual ~VehicleUpdatedEvent() = default;
	private:
		base::EventSpecifier m_event;
	};

	class VehicleMovedEvents final : public VehicleUpdatedEvent
	{
	public:
		VehicleMovedEvents(const std::string& name, const sf::Vector2f& pos)
			: VehicleUpdatedEvent(name, base::EventSpecifier::VEHICLE_MOVED), m_pos(pos) { }
		~VehicleMovedEvents() {}
		const sf::Vector2f& getPos()
		{
			return m_pos;
		}
	private:
		sf::Vector2f m_pos;
	};

	class VehicleDirectionEvent final : public VehicleUpdatedEvent
	{
	public:
		VehicleDirectionEvent(const std::string& name)
			: VehicleUpdatedEvent(name, base::EventSpecifier::VEHICLE_DIRECTION) { }
		~VehicleDirectionEvent() {}
	};

	class GPSUpdateEvent final : public base::IEvent
	{
	public:
		GPSUpdateEvent(const std::string& name, const sf::Vector2f& pos, object::cars::Direction dir)
			: IEvent(name, base::EventSpecifier::GPS_UPDATE), position(pos), direction(dir)
		{}
		~GPSUpdateEvent() = default;
		sf::Vector2f position;
		object::cars::Direction direction;
	};
}
