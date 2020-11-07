#pragma once

#include "EventHandler.h"
#include "MovableEvents.h"

namespace base
{
	class VehicleEventHandler : public EventHandler<event::VehicleUpdatedEvent>
	{
	public:
		using EventHandler::EventHandler;
		~VehicleEventHandler();

		void doHandle(const event::VehicleUpdatedEvent& e) override;

		virtual void doHandleEvent(const event::VehicleMovedEvents& e);
		virtual void doHandleEvent(const event::VehicleDirectionEvent& e);

	};
}