
#include "CarTracker.h"

#include "EventSubription.h"

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
			std::cout << "Added CAR" << std::endl;
			m_vehiclePositions.insert(std::make_pair<std::string, const sf::Vector2f&>(e.getName(), e.getPos()));
		}
	}
}