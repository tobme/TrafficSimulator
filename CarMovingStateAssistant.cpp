#include "CarMovingStateAssistant.h"
#include "IDrawableObject.h"
#include "MovableEvents.h"

#include <random>

using namespace base;
using namespace event;
using namespace map;

using namespace std::chrono;

namespace object {
	namespace cars {

		CarMovingStateAssistant::CarMovingStateAssistant(const std::string& name,
			Subscriber* pSubscriber,
			const Map& map)
			: IMovingAssistant(name)
			, m_pSubscriber(pSubscriber)
			, m_map(map)
			, m_timeSinceLastCheck(high_resolution_clock::now())
			, m_dev()
			, m_rng(m_dev())
		{

		}
		void CarMovingStateAssistant::updateState(const std::string& name, const CarConfig& config, const sf::Vector2f& pos)
		{
			std::cout << " config.turningSafeDistance " << config.turningSafeDistance << std::endl;
			// First check if car has turn state active
			// If so dont do anything
			if (config.turnState != TurnState::GO_FORWARD || config.turningSafeDistance != 0)
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

		// If it's not the last turn it's a chance of 1/5 that it takes an earlier turn.
		TurnState CarMovingStateAssistant::turnEarlier(TurnState turnState, TurnState turnChanceState)
		{
			high_resolution_clock::time_point currentTime(high_resolution_clock::now());

			duration<double> time_span = duration_cast<duration<double>>(currentTime - m_timeSinceLastCheck);

			m_timeSinceLastCheck = currentTime;

			if (turnState != TurnState::GO_FORWARD || time_span.count() < 1.0)
				return turnState;
	
			std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 5);

			if (dist6(m_rng) == 1)
			{
				return turnChanceState;
			}
			else
			{
				return TurnState::GO_FORWARD;
			}
		}

		TurnState CarMovingStateAssistant::checkIfTurnIsOk(const sf::Vector2f& isBlocked, TurnState turnSignal)
		{
			if (!m_map.isWalkable(isBlocked))
				return turnEarlier(turnSignal);
			else
				return turnEarlier(TurnState::GO_FORWARD, turnSignal);
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

				std::uniform_int_distribution<std::mt19937::result_type> dist2(1, 2);

				if (dist2(m_rng) == 5)
				{
					if (m_map.isWalkable(isWalkableToTheRight))
					{
						return checkIfTurnIsOk(isBlockedRight, TurnState::TURN_NEXT_RIGHT);
					}
					else if (m_map.isWalkable(isWalkableToTheLeft))
					{
						return checkIfTurnIsOk(isBlockedLeft, TurnState::TURN_NEXT_LEFT);					}
				}
				else
				{
					if (m_map.isWalkable(isWalkableToTheLeft))
					{
						return checkIfTurnIsOk(isBlockedLeft, TurnState::TURN_NEXT_LEFT);
					}
					else if (m_map.isWalkable(isWalkableToTheRight))
					{
						return checkIfTurnIsOk(isBlockedRight, TurnState::TURN_NEXT_RIGHT);
					}

				}

				checkUpRight = nextMove;
				temp = nextMove;
			}

			return TurnState::GO_FORWARD;
		}
	}
}