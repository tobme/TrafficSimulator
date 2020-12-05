
#include "MovingAssistantHandler.h"

using namespace ::object::cars;
using namespace ::base;

namespace object {
	MovingAssistantHandler::MovingAssistantHandler()
		: IMovingAssistantHandler("MovingAssistantHandler")
		, m_assistants()
	{
	}

	MovingAssistantHandler::~MovingAssistantHandler()
	{
	}

	void MovingAssistantHandler::addAssistant(IMovingAssistantSP assistant)
	{
		m_assistants.push_back(assistant);
	}

	void MovingAssistantHandler::updateAssistants(const std::string& name, const CarConfig& config, const sf::Vector2f& pos)
	{
		for (auto& assistant : m_assistants)
		{
			assistant->updateState(name, config, pos);
		}
	}
}