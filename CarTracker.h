#pragma once

#include "ICarTracker.h"

#include "EventHandler.h"
#include "VehicleCreatedEvents.h"
#include "Subscriber.h"

namespace object {
	namespace tracker {
		class CarTracker
			: public ICarTracker
			, public base::EventHandler<event::VehicleCreated>
		{
		public:
			CarTracker(const std::string& name, base::Subscriber* pSubscriber);

			~CarTracker();

			void doHandle(const event::VehicleCreated& e) override;

			const sf::Vector2f& getPosByName(const std::string& name) const override;

			/*
			* Search that vehicle is within the area.
			* @param name   Doesn't include the vehicle with that name in the search.
			* 
			* @returns true if a vehicle is found.
			*/
			bool isVehicleWithinArea(const sf::Vector2f& topLeftCorner, const sf::Vector2f& bottomRightCorner, const std::string& name = "") const override;
		private:
			std::vector<std::pair<std::string, const sf::Vector2f*>> m_vehiclePositions;
		};
	}
}