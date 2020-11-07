#pragma once

#include "WalkableProp.h"
#include "Subscriber.h"

namespace road {
	class VerticalRoad : public object::WalkableRectangleProp {
	public:
		VerticalRoad(const std::string& name, base::Subscriber* pSubscriber, const sf::Vector2f& pos);
		~VerticalRoad();
	private:
		static unsigned int index;
	};
}