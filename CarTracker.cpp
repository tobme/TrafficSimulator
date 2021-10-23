
#include "CarTracker.h"

#include "EventSubription.h"

#include <algorithm>

using namespace ::base;
using namespace ::event;

namespace object {
	namespace tracker {
		CarTracker::CarTracker(const std::string& name, Subscriber* pSubscriber)
			: ICarTracker(name)
			, m_vehiclePositions()
		{
			pSubscriber->subscribe(VehicleCreatedSubscription, this);
		}
		CarTracker::~CarTracker()
		{

		}
		void CarTracker::doHandle(const event::VehicleCreated& e)
		{
			std::cout << "Added CAR " << e.getPos()->x << " " << e.getPos()->y << std::endl;
			
			m_vehiclePositions.push_back(std::make_pair<std::string, const sf::Vector2f*>(e.getName(), e.getPos()));
		}
		const sf::Vector2f& CarTracker::getPosByName(const std::string& name) const
		{
			auto it = std::find_if(m_vehiclePositions.begin(), m_vehiclePositions.end(), [&name](auto && posPair)
				{
					return posPair.first == name;
				});

			if (it != m_vehiclePositions.end())
				return *it->second;

			// Not valid pos
			return sf::Vector2f(-1, -1);
		}
		
		bool CarTracker::isVehicleWithinArea(const sf::Vector2f& topLeftCorner, const sf::Vector2f& bottomRightCorner, const std::string& name) const
		{
			for (auto&& posPair : m_vehiclePositions)
			{
				// Exclude a vehicle.
				if (posPair.first == name)
				{
					continue;
				}

				if (topLeftCorner.x <= posPair.second->x
					&& bottomRightCorner.x >= posPair.second->x
					&& topLeftCorner.y <= posPair.second->y
					&& bottomRightCorner.y >= posPair.second->y)
				{
					return true;
				}
			}

			return false;
		}
	}
}