#pragma once

#include "Taxi.h"

#include "MovableObject.h"
#include "Subscriber.h"

namespace shape {
	namespace cars {

		class Taxi : public object::cars::MovableObject
		{
		public:

			Taxi(const std::string& name, base::Subscriber* pSubscriber, const sf::Vector2f& pos);
			~Taxi();
		private:
			static unsigned int index;
		};
	}

}

