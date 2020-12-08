#include "MovableObject.h"
#include "EventSubription.h"
#include "VehicleCreatedEvents.h"

#include <SFML/Graphics.hpp>

#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

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
			, m_turningSpeed(0)
			, m_rotationAngle(0)
		{
			pSubscriber->subscribe(event::VehicleMoveSubscription, this);
			pSubscriber->subscribe(event::VehicleSetTurnSubscription, this);
			pSubscriber->subscribe(event::VehiclePedalSubscription, this);
			pSubscriber->subscribe(event::VehicleTurningSubscription, this);

			pSubscriber->dispatchEvent(VehicleCreated(name, pos));
		}


		MovableObject::~MovableObject()
		{
		}

		//! The position has it's origin in top left corner.
		//! Convert it to the front left corner instead.
		sf::Vector2f getRotationalForwardPos(const sf::Vector2f& pos, const CarConfig& m_config)
		{
			switch (m_config.direction)
			{
			case Direction::EAST:
				return sf::Vector2f(pos.x + 50, pos.y);
			case Direction::NORTH:
			case Direction::WEST:
				return pos;
			case Direction::SOUTH:
				return sf::Vector2f(pos.x, pos.y + 50);
			}
			return pos;
		}
		

		//! Start the chain by updating it's GPS signal
		void MovableObject::updateTrigger()
		{
			auto pos = getRotationalForwardPos(getShape()->getPosition(), m_config);

			updateCar();

			GPSUpdateEvent event = GPSUpdateEvent(getName(), pos, m_config);
			m_pSubscriber->dispatchEvent<GPSUpdateEvent>(event);
		}

		void MovableObject::setNewDirection()
		{
			int currentVal = m_config.direction;

			// @todo Override operator instead
			if (m_config.dirState == DirectionState::TURNING_LEFT)
			{
				currentVal--;
			}
			else
			{
				currentVal++;
			}

			if (currentVal < 0)
				currentVal = 3;
			else if (currentVal > 3)
				currentVal = 0;

		    m_config.direction = static_cast<Direction>(currentVal);
		}

		bool MovableObject::checkIfFinishedTurning()
		{
			if (m_rotationAngle >= 90.0f)
			{
				setNewDirection();
				m_config.dirState = DirectionState::STANDARD;
				m_config.turnState = TurnState::GO_FORWARD;
				m_rotationAngle = 0.0f;
				return true;
			}
			return false;
		}

		void MovableObject::setRotationPos()
		{
			if (m_rotationAngle == 0.0f)
			{
				auto pos = getShape()->getPosition();

				auto partX = (int)pos.x % 50;
				auto partY = (int)pos.y % 50;

				int newPosX(0);
				int newPosY(0);

				if (partX > 25)
				{
					newPosX = (int)pos.x + (50 - partX);
				}
				else
				{
					newPosX = (int)pos.x - partX;
				}

				if (partY > 25)
				{
					newPosY = (int)pos.y + (50 - partY);
				}
				else
				{
					newPosY = (int)pos.y - partY;
				}

				setTopLeftPos(newPosX, newPosY);

				std::cout << "setting pos" << "pos x" << getTopLeftPos().x << " pos y " << getTopLeftPos().y << std::endl;

			}
		}

		int turningindex(0);

		float MovableObject::getTurningSpeed()
		{
			//! For now set m_speed to static during turns
			//! For future, make brake dynamic
			if (m_config.dirState == DirectionState::STANDARD)
			{
				return 0.0f;
			}

			

			auto pShape = getShape();

			setRotationPos();

			if (checkIfFinishedTurning())
			{
				return 0.0f;
			}

			m_speed = 2.5f;
			m_rotationAngle += 4.5;

			if (m_config.dirState == DirectionState::TURNING_LEFT)
			{
				pShape->rotate(-4.5f);
				return 0.5f;
			}
			else
			{
				pShape->rotate(4.5f);
				return -0.5f;
			}
			
		}

		void MovableObject::move()
		{
			auto pShape = getShape();

			m_turningSpeed = getTurningSpeed();

			m_config.turningSafeDistance -= m_speed;
			m_config.turningSafeDistance = std::max(0, m_config.turningSafeDistance);

			switch (m_config.direction)
			{
			case Direction::EAST:
				pShape->move(m_speed, -m_turningSpeed);
				break;
			case Direction::NORTH:
				pShape->move(-m_turningSpeed, -m_speed);
				break;
			case Direction::SOUTH:
				pShape->move(m_turningSpeed, m_speed);
				break;
			case Direction::WEST:
				pShape->move(-m_speed, m_turningSpeed);
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
			if (m_config.state == PedalState::GAS)
			{
				m_speed += m_config.accMultiplier;
				m_speed = std::min(m_speed, (float)m_config.maxSpeed);
			}
			else
			{
				m_speed -= m_config.decMultiplier;
				// If break, set lowest speed to make sure it doesnt stop before turn

				if (m_config.state == PedalState::BREAK)
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

		void MovableObject::doHandleEvent(const event::VehicleSetTurnEvent& e)
		{
			if (e.getName() == getName())
			{
				std::cout << "Setting turn state " << e.newTurnState << std::endl;
				m_config.turnState = e.newTurnState;
				m_config.turningSafeDistance = std::max(m_config.turningSafeDistance, 50);
			}
		}

		void MovableObject::doHandleEvent(const event::VehiclePedalEvent& e)
		{
			if (e.getName() == getName())
			{
				std::cout << "Setting pedal state " << e.newPedalState << std::endl;
				m_config.state = e.newPedalState;
			}
		}

		void MovableObject::doHandleEvent(const event::VehicleTurningEvent& e)
		{
			if (e.getName() == getName())
			{
				std::cout << "Setting dir state " << e.newDirState << std::endl;
				m_config.dirState = e.newDirState;

				if (m_config.dirState == DirectionState::TURNING_LEFT)
					m_config.turningSafeDistance = std::max(m_config.turningSafeDistance, 160);
			}
		}
		
	}
}