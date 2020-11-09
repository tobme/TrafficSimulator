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
			, RectangleObject(name, std::make_unique<RectangleShape>(Vector2f(PROP_SIZE, PROP_SIZE)), textureName, pos, drawingorder)
			, m_config()
			, m_pSubscriber(pSubscriber)
			, m_speed(0)
		{
			VehicleMovedEvents e = VehicleMovedEvents(name, sf::Vector2f(123,0));
			pSubscriber->subscribe(event::VehicleMoveSubscription, this);
			pSubscriber->subscribe(event::VehicleTurnSubscription, this);
			pSubscriber->subscribe(event::VehiclePedalSubscription, this);
		}


		MovableObject::~MovableObject()
		{
		}

		//! Start the chain by updating it's GPS signal
		void MovableObject::updateTrigger()
		{
			auto shape = getShape();
			auto pos = shape->getPosition();

			updateCar();

			GPSUpdateEvent event = GPSUpdateEvent(getName(), pos, m_config);
			m_pSubscriber->dispatchEvent<GPSUpdateEvent>(event);

		}

		void MovableObject::move()
		{
			auto pShape = getShape();

			switch (m_config.direction)
			{
			case Direction::EAST:
				pShape->move(m_speed, 0);
				break;
			case Direction::NORTH:
				pShape->move(0, -m_speed);
				break;
			case Direction::SOUTH:
				pShape->move(0, m_speed);
				break;
			case Direction::WEST:
				pShape->move(-m_speed, 0);
				break;
			}
		}

		void MovableObject::updateCar()
		{
			updateCarSpeed();

			move();
		}

		void MovableObject::updateCarSpeed()
		{
			if (m_config.state == State::GAS)
			{
				m_speed += m_config.accMultiplier;
				m_speed = std::min(m_speed, (float)m_config.maxSpeed);
			}
			else
			{
				m_speed -= m_config.decMultiplier;
				// If break, set lowest speed to make sure it doesnt stop before turn

				if (m_config.state == State::BREAK)
				{
					m_speed = std::max(m_speed, 1.0f);
				}
				else
				{
					m_speed = std::max(m_speed, 0.0f);
				}

			}
		}

		void MovableObject::doHandleEvent(const VehicleMovedEvents& e)
		{

		}

		void MovableObject::doHandleEvent(const VehicleDirectionEvent& e)
		{
		}

		void MovableObject::doHandleEvent(const event::VehicleTurnEvent& e)
		{
			if (e.getName() == getName())
			{
				std::cout << "Setting turn state" << std::endl;
				m_config.turnState = e.newTurnState;
			}

		}

		void MovableObject::doHandleEvent(const event::VehiclePedalEvent& e)
		{
			if (e.getName() == getName())
			{
				std::cout << "Setting pedal state" << std::endl;
				m_config.state = e.newPedalState;
			}
		}
		
	}
}