#pragma once

namespace object {
	namespace cars {

		enum Direction {
			NORTH = 0,
			EAST = 1,
			SOUTH = 2,
			WEST = 3,
		};
		enum PedalState {
			GAS,
			BREAK,
			STOP,
			PARKED
		};

		enum TurnState {
			GO_FORWARD,
			TURN_NEXT_RIGHT,
			TURN_NEXT_LEFT,
		};

		enum DirectionState {
			STANDARD,
			TURNING_RIGHT,
			TURNING_LEFT
		};

		struct CarConfig {
			Direction direction = Direction::WEST;
			PedalState state = PedalState::GAS;
			TurnState turnState = TurnState::GO_FORWARD;
			DirectionState dirState = DirectionState::STANDARD;
			float accMultiplier = 0.1f;
			int maxSpeed = 7;
			float decMultiplier = 0.2f;
		};
	}
}