#include "CarMovingStateAssistant.h"
#include "IDrawableObject.h"
#include "MovableEvents.h"

using namespace base;
using namespace event;
using namespace map;

namespace object {
	namespace cars {

		CarMovingStateAssistant::CarMovingStateAssistant(const std::string& name,
			Subscriber* pSubscriber,
			const Map& map)
			: IMovingAssistant(name)
			, m_pSubscriber(pSubscriber)
			, m_map(map)
		{

		}
		void CarMovingStateAssistant::updateState(const std::string& name, const CarConfig& config, const sf::Vector2f& pos)
		{
			// First check if car has turn state active
			// If so dont do anything
			if (config.turnState != TurnState::FORWARD)
			{
				return;
			}


			// Check if there are any other possible turns before road ends
			// If so return

			// If not, then dispatch turn state
			if (!canTurn(config, pos))
			{
				//! @todo need to check which way to turn
				VehicleTurnEvent e = VehicleTurnEvent(name, TurnState::TURN_LEFT);
				m_pSubscriber->dispatchEvent(e);
			}


		}
		bool CarMovingStateAssistant::canTurn(const CarConfig& config, const sf::Vector2f& pos)
		{
			sf::Vector2f temp = pos;
			sf::Vector2f nextMove = pos;
			sf::Vector2f isWalkable1;
			sf::Vector2f isWalkable2;
			sf::Vector2f isBlocked;

			while (m_map.isWalkable(temp))
			{
				switch (config.direction)
				{
				case Direction::EAST:
					nextMove.x += PROP_SIZE;
					break;
				case Direction::NORTH:
					nextMove.y -= PROP_SIZE;
					break;
				case Direction::SOUTH:
					nextMove.y += PROP_SIZE;
					break;
				case Direction::WEST:
					nextMove.x -= PROP_SIZE;
					break;
				}
				isBlocked = m_map.toTheUp(nextMove, config.direction);
				isWalkable1 = m_map.toTheLeft(temp, config.direction);
				isWalkable2 = m_map.toTheRight(temp, config.direction);

				if ((m_map.isWalkable(isWalkable1) || m_map.isWalkable(isWalkable2)) && m_map.isWalkable(isBlocked))
					return true;

				temp = nextMove;

			}

			return false;
		}
	}
}