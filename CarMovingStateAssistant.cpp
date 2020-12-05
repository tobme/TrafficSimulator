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
			if (config.turnState != TurnState::GO_FORWARD)
			{
				return;
			}


			// Check if there are any other possible turns before road ends
			// If so return
			TurnState turnState = canTurn(config, pos);

			// If not, then dispatch turn state
			if (turnState != TurnState::GO_FORWARD)
			{
				VehicleSetTurnEvent e = VehicleSetTurnEvent(name, turnState);
				m_pSubscriber->dispatchEvent(e);
			}


		}

		TurnState CarMovingStateAssistant::canTurn(const CarConfig& config, const sf::Vector2f& pos)
		{
			sf::Vector2f temp = pos;
			sf::Vector2f nextMove = pos;
			sf::Vector2f checkUpRight = pos;
			sf::Vector2f isWalkableToTheLeft;
			sf::Vector2f isWalkableToTheRight;
			sf::Vector2f isBlockedRight;
			sf::Vector2f isBlockedLeft;

			while (m_map.isWalkable(temp))
			{
				switch (config.direction)
				{
				case Direction::EAST:
					nextMove.x += PROP_SIZE;
					checkUpRight.x += PROP_SIZE * 2;
					break;
				case Direction::NORTH:
					nextMove.y -= PROP_SIZE;
					checkUpRight.y -= PROP_SIZE * 2;
					break;
				case Direction::SOUTH:
					nextMove.y += PROP_SIZE;
					checkUpRight.y += PROP_SIZE * 2;
					break;
				case Direction::WEST:
					nextMove.x -= PROP_SIZE;
					checkUpRight.x -= PROP_SIZE * 2;
					break;
				}
				isBlockedRight = m_map.toTheUp(checkUpRight, config.direction);
				isBlockedLeft = m_map.toTheUp(nextMove, config.direction);
				isWalkableToTheLeft = m_map.toTheLeft(temp, config.direction);
				isWalkableToTheRight = m_map.toTheRight(temp, config.direction);

				if (m_map.isWalkable(isWalkableToTheRight))
				{
					if (!m_map.isWalkable(isBlockedRight))
						return TurnState::TURN_NEXT_RIGHT;
					else
						return TurnState::GO_FORWARD;
				}
				else if (m_map.isWalkable(isWalkableToTheLeft))
				{
					if (!m_map.isWalkable(isBlockedLeft))
						return TurnState::TURN_NEXT_LEFT;
					else
						return TurnState::GO_FORWARD;
				}

				checkUpRight = nextMove;
				temp = nextMove;
			}

			return TurnState::GO_FORWARD;
		}
	}
}