#include "CarSimulator.h"
#include "EventSubription.h"

using namespace base;
using namespace event;
using namespace map;

namespace object {
	namespace cars {
		CarSimulator::CarSimulator(const std::string& name,
			const Map& map,
			Subscriber* pSubscriber,
			Config config)
			: EventHandler<event::GPSUpdateEvent>()
			, ITriggable()
			, IObject(name)
			, m_map(map)
			, m_pSubscriber(pSubscriber)
			, m_spIMovingAssistantHandler(config.spIMovingAssistantHandler)
		{
			m_pSubscriber->subscribe(GPSUpdateSubscription, this);
		}

		// Car send gps update...
		// Start of simulation
		void CarSimulator::doHandle(const GPSUpdateEvent& event)
		{
			std::string name = event.getName();
			auto& pos = event.position;
			auto& config = event.config;

			//! Updates all of the moving assistants.
			m_spIMovingAssistantHandler->updateAssistants(name, config, pos);
		}

		// NEEDED? doHandle and trigger work on different threads
		// Avoid if possible
		void CarSimulator::updateTrigger()
		{
		}

	}
}