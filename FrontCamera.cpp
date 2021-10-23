
#include "FrontCamera.h"

using namespace ::object::tracker;

constexpr int SEARCH_WIDTH = 50;
constexpr int SEARCH_LENGTH = 150;

namespace object {
	namespace cars {
		FrontCamera::FrontCamera(const std::string& vehicleName, const ICarTracker* pCarTracker)
			: m_vehicleName(vehicleName), m_pCarTracker(pCarTracker)
		{
		}
		FrontCamera::~FrontCamera() = default;

		bool FrontCamera::objectAhead(const sf::Vector2f& myPos, Direction dir) const
		{
			switch (dir)
			{
			case Direction::EAST:
				return m_pCarTracker->isVehicleWithinArea(sf::Vector2f(myPos.x + 50, myPos.y), sf::Vector2f(myPos.x + 50 + SEARCH_LENGTH, myPos.y + SEARCH_WIDTH), m_vehicleName);
			case Direction::NORTH:
				return m_pCarTracker->isVehicleWithinArea(sf::Vector2f(myPos.x, myPos.y - SEARCH_LENGTH), sf::Vector2f(myPos.x + SEARCH_WIDTH, myPos.y), m_vehicleName);
			case Direction::SOUTH:
				return m_pCarTracker->isVehicleWithinArea(sf::Vector2f(myPos.x, myPos.y + 50), sf::Vector2f(myPos.x + SEARCH_WIDTH, myPos.y + 50 + SEARCH_LENGTH), m_vehicleName);
			case Direction::WEST:
				return m_pCarTracker->isVehicleWithinArea(sf::Vector2f(myPos.x - SEARCH_LENGTH, myPos.y), sf::Vector2f(myPos.x, myPos.y + SEARCH_WIDTH), m_vehicleName);
			default:
				return false;
			}
		}
	}
}