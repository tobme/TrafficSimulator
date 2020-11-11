#pragma once

#include "IEvents.h"
namespace event
{
	static const base::EventSpecifier VehicleMoveSubscription = base::EventSpecifier::VEHICLE_MOVED;
	static const base::EventSpecifier VehicleDirectionChangeSubscription = base::EventSpecifier::VEHICLE_DIRECTION;
	static const base::EventSpecifier GPSUpdateSubscription = base::EventSpecifier::GPS_UPDATE;
	static const base::EventSpecifier VehicleSetTurnSubscription = base::EventSpecifier::VEHICLE_SET_TURN;
	static const base::EventSpecifier VehiclePedalSubscription = base::EventSpecifier::VEHICLE_PEDAL;
	static const base::EventSpecifier VehicleTurningSubscription = base::EventSpecifier::VEHICLE_TURNING;
}