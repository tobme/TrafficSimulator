#pragma once

namespace object {
	namespace cars {

		enum Direction {
			WEST,
			EAST,
			NORTH,
			SOUTH
		};
		enum State {
			GAS,
			BREAK,
			PARKED
		};

		enum TurnState {
			FORWARD,
			TURN_RIGHT,
			TURN_LEFT
		};

		struct CarConfig {
			Direction direction = Direction::WEST;
			State state = State::GAS;
			TurnState turnState = TurnState::FORWARD;
			float accMultiplier = 0.1f;
			int maxSpeed = 7;
			float decMultiplier = 0.2f;
		};
	}
}