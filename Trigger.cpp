#include "Trigger.h"

#include<algorithm>
#include<chrono>
#include <functional>
#include <mutex>
#include <iostream>

namespace base {


		static const int SLEEP_TIME = 20;

		void Trigger::pushTrigger()
		{
			std::unique_lock<std::mutex> lock(m_mutex);
			lock.unlock();

			while (true)
			{
				lock.lock();
				for (auto p : m_triggerList)
				{
					p.first->updateTrigger();
				}
				lock.unlock();

				// Updates
				std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			}
		}

	Trigger::Trigger(const std::string& name)
		: IObject(name), m_triggerList(), m_timeElapsed(), m_mutex(), m_triggerThread(&Trigger::pushTrigger, this)
	{
	}


	Trigger::~Trigger()
	{
	}

	void Trigger::updateTrigger() const
	{
		for (TriggablePair triggable : m_triggerList)
		{
			triggable.first->updateTrigger();
		}
	}

	void Trigger::addTriggable(ITriggable* object, TimeElapsed timeElapsed)
	{
		const std::lock_guard<std::mutex> lock(m_mutex);

		m_triggerList.push_back(TriggablePair(object, timeElapsed));

		std::sort(m_triggerList.begin(), m_triggerList.end(),
			[](auto p1, auto p2)
			{
				return p1.second < p2.second;
			});
	}

}