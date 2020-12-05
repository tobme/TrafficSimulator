#include "TurningStateAssistant.h"
#include "IDrawableObject.h"
#include "MovableEvents.h"
#include<thread>

using namespace base;
using namespace event;
using namespace map;

namespace object {
	namespace cars {

		TurningStateAssistant::TurningStateAssistant(const std::string& name,
			Subscriber* pSubscriber,
			const Map& map)
			: IMovingAssistant(name)
			, m_pSubscriber(pSubscriber)
			, m_map(map)
		{

		}
		void TurningStateAssistant::updateState(const std::string& name, const CarConfig& config, const sf::Vector2f& pos)
		{
			//std::cout << "Vehiclepos " << pos.x << " " << pos.y << std::endl;

			// If it isn't planning on turning or if it's already turning
			// Return
			if (config.turnState == TurnState::GO_FORWARD || config.dirState != DirectionState::STANDARD)
			{
				return;
			}

			if (config.turnState == TurnState::TURN_NEXT_LEFT)
			{
				Turn(name, config, pos, &Map::toTheLeft, DirectionState::TURNING_LEFT);
			}
			else
			{
				Turn(name, config, pos, &Map::toTheRight, DirectionState::TURNING_RIGHT);
			}

		}

		void TurningStateAssistant::Turn(const std::string& name,
			const CarConfig& config,
			const sf::Vector2f& pos,
			const sf::Vector2f (Map::*func)(const sf::Vector2f&, Direction) const,
			DirectionState dirState)
		{
			sf::Vector2f temp = pos;
			sf::Vector2f isWalkable;

			//switch (config.direction)
			//{
			//case Direction::EAST:
			//	temp.x += PROP_SIZE;
			//	break;
			//case Direction::NORTH:
			//	temp.y -= PROP_SIZE;
			//	break;
			//case Direction::SOUTH:
			//	temp.y += PROP_SIZE;
			//	break;
			//case Direction::WEST:
			//	temp.x -= PROP_SIZE;
			//	break;
			//}

			isWalkable = (m_map.*func)(temp, config.direction);

			if (m_map.isWalkable(isWalkable))
			{

				VehicleTurningEvent e = VehicleTurningEvent(name, dirState);
				m_pSubscriber->dispatchEvent(e);
			}
		}
	}
}