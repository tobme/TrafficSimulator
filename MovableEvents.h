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

	class VehicleSetTurnEvent final : public VehicleUpdatedEvent
	{
	public:
		VehicleSetTurnEvent(const std::string& name, object::cars::TurnState turnState)
			: VehicleUpdatedEvent(name, base::EventSpecifier::VEHICLE_SET_TURN), newTurnState(turnState)
		{ }
		~VehicleSetTurnEvent() {}
		object::cars::TurnState newTurnState;
	};

	class VehiclePedalEvent final : public VehicleUpdatedEvent
	{
	public:
		VehiclePedalEvent(const std::string& name, object::cars::PedalState pedalState)
			: VehicleUpdatedEvent(name, base::EventSpecifier::VEHICLE_PEDAL), newPedalState(pedalState)
		{ }
		~VehiclePedalEvent() {}
		object::cars::PedalState newPedalState;
	};

	class VehicleTurningEvent final : public VehicleUpdatedEvent
	{
	public:
		VehicleTurningEvent(const std::string& name, object::cars::DirectionState dirState)
			: VehicleUpdatedEvent(name, base::EventSpecifier::VEHICLE_TURNING), newDirState(dirState)
		{ }
		~VehicleTurningEvent() {}
		object::cars::DirectionState newDirState;
	};

	class GPSUpdateEvent final : public base::IEvent
	{
	public:
		GPSUpdateEvent(const std::string& name, const sf::Vector2f& pos, const object::cars::CarConfig& cfg)
			: IEvent(name, base::EventSpecifier::GPS_UPDATE), position(pos), config(cfg)
		{}
		~GPSUpdateEvent() = default;
		sf::Vector2f position;
		object::cars::CarConfig config;
	};
}
