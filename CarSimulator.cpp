#include "CarSimulator.h"
#include "EventSubription.h"

using namespace base;
using namespace event;
using namespace map;

namespace object {
	namespace cars {
		CarSimulator::CarSimulator(const std::string& name, const Map& map, Subscriber* pSubscriber)
			: EventHandler<event::GPSUpdateEvent>()
			, ITriggable()
			, IObject(name)
			, m_map(map)
			, m_pSubscriber(pSubscriber)
		{
			m_pSubscriber->subscribe(GPSUpdateSubscription, this);
		}

		// Car send gps update...
		// Start of simulation
		void CarSimulator::doHandle(const GPSUpdateEvent& event)
		{
			std::string name = event.getName();
			auto pos = event.position;
			std::cout << "test2" << std::endl;

			// Need to translate map index to map position
			// Make every object 50x50? Or loop map?

			// 50 x 50 sounds good for efficiency
		}

		// NEEDED? doHandle and trigger work on different threads
		// Avoid if possible
		void CarSimulator::updateTrigger()
		{
		}

	}
}