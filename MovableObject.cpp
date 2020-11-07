#include "MovableObject.h"
#include "EventSubription.h"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace base;
using namespace event;

namespace object {
	namespace cars {



		MovableObject::MovableObject(const std::string& name, const TextureId& textureName, Subscriber* pSubscriber, const sf::Vector2f& pos, unsigned int drawingorder)
			: ITriggable()
			, RectangleObject(name, std::make_unique<RectangleShape>(Vector2f(100,50)), textureName, pos, drawingorder)
			, m_direction(WEST)
			, m_state(STARTED)
			, m_pSubscriber(pSubscriber)
		{
			VehicleMovedEvents e = VehicleMovedEvents(name, sf::Vector2f(123,0));
			pSubscriber->subscribe(event::VehicleMoveSubscription, this);
			//pSubscriber->dispatchEvent<VehicleMovedEvents>(e);
		}


		MovableObject::~MovableObject()
		{
		}

		//! Start the chain by updating it's GPS signal
		void MovableObject::updateTrigger()
		{
			auto shape = getShape();
			auto pos = shape->getPosition();

			GPSUpdateEvent event = GPSUpdateEvent(getName(), pos, m_direction);
			std::cout << "test" << std::endl;
			m_pSubscriber->dispatchEvent<GPSUpdateEvent>(event);

		}

		void MovableObject::move(float x, float y)
		{
			auto pShape = getShape();
			pShape->move(x, y);
		}

		void MovableObject::doHandleEvent(const VehicleMovedEvents& e)
		{

		}

		void MovableObject::doHandleEvent(const VehicleDirectionEvent& e)
		{

		}
		
	}
}