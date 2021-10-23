#include "Taxi.h"

#include "TextureId.h"

using namespace ::base;
using namespace ::object::cars;
namespace shape {
	namespace cars {

		unsigned int Taxi::index(1);

		Taxi::Taxi(const std::string& name, Subscriber* pSubscriber, const sf::Vector2f& pos, ICameraSP spCamera)
			: MovableObject(name + std::to_string(index++), TaxiId, pSubscriber, pos, 2, spCamera)
		{
		}


		Taxi::~Taxi()
		{
		}
	}
}
