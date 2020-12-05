
#pragma once

#include "IMovingAssistantHandler.h"

namespace object {

	//! @brief Handles all of the moving assistants.
	//! Keep in mind that order of assistants matter.
	class MovingAssistantHandler : public IMovingAssistantHandler
	{
	public:
		MovingAssistantHandler();

		~MovingAssistantHandler();

		void addAssistant(cars::IMovingAssistantSP assistant) override;

		void updateAssistants(const std::string& name, const cars::CarConfig& config, const sf::Vector2f& pos) override;
	private:
		std::vector<cars::IMovingAssistantSP> m_assistants;
	};
}