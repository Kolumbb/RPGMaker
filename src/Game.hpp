#pragma once

#include "stdafx.hpp"
#include "StateData.hpp"
#include "states/GameState.hpp"
#include "states/MainMenuState.hpp"

class Game{
private:
	//Variables & Resources
	bool quit;
	sf::Clock clock;
	sf::Event event;
	float dt;
	sf::Vector2f mousePosition;
	StateData stateData;

	//Private methods
	auto getQuit() -> const bool const;
	
	//Update methods
	auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
	auto updateEvents() -> void;
	auto updateDt() -> void;
	auto initStates() -> void;
	
	//Render methods
	auto render(sf::RenderTarget* target = nullptr) -> void;
	
protected:
public:
	//Constructors & Destructors
	Game();
	~Game() = default;

	//Public methods
	auto run() ->void;
};

