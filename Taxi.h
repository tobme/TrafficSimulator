#pragma once

#include "Taxi.h"

#include "MovableObject.h"
#include "Subscriber.h"
#include "ICamera.h"

namespace shape {
	namespace cars {

		class Taxi : public object::cars::MovableObject
		{
		public:

			Taxi(const std::string& name, base::Subscriber* pSubscriber, const sf::Vector2f& pos, object::cars::ICameraSP spCamera);
			~Taxi();
		private:
			static unsigned int index;
		};
	}

}

