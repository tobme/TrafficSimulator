#pragma once

#include "ICarTracker.h"

#include "EventHandler.h"
#include "VehicleCreatedEvents.h"
#include "Subscriber.h"

#include<unordered_map>

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
		private:
			std::unordered_map<std::string, const sf::Vector2f&> m_vehiclePositions;
		};
	}
}