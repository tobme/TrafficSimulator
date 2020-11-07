#pragma once

#include "ITriggable.h"
#include "IObject.h"

#include<vector>
#include<thread>
#include<mutex>

namespace base {

	enum TimeElapsed : unsigned int
	{
		ELAPSED_0 = 0,
		ELAPSED_20 = 1,
		ELAPSED_50 = 2,
		ELAPSED_90 = 3
	};

	class Trigger : public IObject
	{
	public:
		using TriggablePair = std::pair<ITriggable*, TimeElapsed>;

		Trigger(const std::string& name);
		~Trigger();

		void updateTrigger() const;
		void addTriggable(ITriggable* object, TimeElapsed timeElapsed);
	private:
		void pushTrigger();

		std::vector<TriggablePair> m_triggerList;
		TimeElapsed m_timeElapsed;
		std::mutex m_mutex;
		std::thread m_triggerThread;
	};
	using TriggerSP = std::shared_ptr<Trigger>;
}
