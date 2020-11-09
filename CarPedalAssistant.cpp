#pragma once
#include "CarPedalAssistant.h"
#include "IDrawableObject.h"
#include "MovableEvents.h"

using namespace base;
using namespace event;
using namespace map;

namespace object {
	namespace cars {

		CarPedalAssistant::CarPedalAssistant(const std::string& name,
			Subscriber* pSubscriber,
			const Map& map)
			: IMovingAssistant(name)
			, m_pSubscriber(pSubscriber)
			, m_map(map)
		{

		}
		void CarPedalAssistant::updateState(const std::string& name, const CarConfig& config, const sf::Vector2f& pos)
		{
			//! Check for turn
			if (config.turnState != TurnState::FORWARD)
			{
				//! If turning and close to turn hit brake pedal
				if (config.state == State::GAS && closeToTurn(config, pos))
				{
					VehiclePedalEvent e = VehiclePedalEvent(name, State::BREAK);
					m_pSubscriber->dispatchEvent(e);
				}
			}
			else if (config.state != State::GAS)
			{
				//! If not turning and not gasing hit gas.
				VehiclePedalEvent e = VehiclePedalEvent(name, State::GAS);
				m_pSubscriber->dispatchEvent(e);
			}

			//! @todo add checks here for red light.
			//! dont use brake, use stop condition.
		}

		bool CarPedalAssistant::closeToTurn(const CarConfig& config, const sf::Vector2f& pos)
		{
			sf::Vector2f temp = pos;
			sf::Vector2f turnPos;

			//! Consider close if < 2 blocks from.
			for (int i = 0; i < 2; i++)
			{
				switch (config.direction)
				{
				case Direction::EAST:
					temp.x += PROP_SIZE;
					break;
				case Direction::NORTH:
					temp.y -= PROP_SIZE;
					break;
				case Direction::SOUTH:
					temp.y += PROP_SIZE;
					break;
				case Direction::WEST:
					temp.x -= PROP_SIZE;
					break;
				}

				if (config.turnState == TurnState::TURN_LEFT)
				{
					turnPos = m_map.toTheLeft(temp, config.direction);

					if (m_map.isWalkable(turnPos))
					{
						return true;
					}
				}
				else
				{
					turnPos = m_map.toTheRight(temp, config.direction);

					if (m_map.isWalkable(turnPos))
					{
						return true;
					}
				}
			}

			return false;
		}
	
	}
}