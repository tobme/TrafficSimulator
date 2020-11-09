#include "VehicleEventHandler.h"

using namespace event;

namespace base {


	VehicleEventHandler::~VehicleEventHandler()
	{
	}

	void VehicleEventHandler::doHandle(const VehicleUpdatedEvent& e)
	{
		switch (e.getEvent())
		{
		case EventSpecifier::VEHICLE_MOVED:
			doHandleEvent(dynamic_cast<const VehicleMovedEvents&>(e));
			break;
		case EventSpecifier::VEHICLE_DIRECTION:
			doHandleEvent(dynamic_cast<const VehicleDirectionEvent&>(e));
			break;
		case EventSpecifier::VEHICLE_TURN:
			doHandleEvent(dynamic_cast<const VehicleTurnEvent&>(e));
			break;
		case EventSpecifier::VEHICLE_PEDAL:
			doHandleEvent(dynamic_cast<const VehiclePedalEvent&>(e));
			break;
		}

	}

	void VehicleEventHandler::doHandleEvent(const VehicleMovedEvents& e)
	{

	}

	void VehicleEventHandler::doHandleEvent(const VehicleDirectionEvent& e)
	{
	}

	void VehicleEventHandler::doHandleEvent(const VehicleTurnEvent& e)
	{
	}

	void VehicleEventHandler::doHandleEvent(const VehiclePedalEvent& e)
	{
	}

}
