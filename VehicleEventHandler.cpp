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
		}
		
	}

	void VehicleEventHandler::doHandleEvent(const VehicleMovedEvents& e)
	{

	}

	void VehicleEventHandler::doHandleEvent(const VehicleDirectionEvent& e)
	{
	}

}
