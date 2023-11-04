#pragma once

#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "StateData.hpp"


class Game
{
private:
	//Variables & Resources
	sf::Clock clock;
	sf::Event event;
	float dt;
	bool running;
	sf::Vector2f mousePosition;
	std::unique_ptr<sf::RenderWindow> window;

	StateData stateData;

	

	bool quit;
	
	
	//Private methods
	auto getQuit() -> bool const;
	//Initializers
	auto initWindow() -> void;
	auto initSupportedKeys() -> void;
	auto initStates() -> void;
	auto initStateData() -> void;
	auto initGfxSettings() -> void;
	auto initFont() -> void;
	
	//Update methods
	auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
	auto updateEvents() -> void;
	auto updateDt() -> void;
	
	//Render methods
	auto render(sf::RenderTarget* target = nullptr) -> void;
	
protected:
public:
	//Constructors & Destructors
	Game();
	~Game();

	//Public methods
	auto run() ->void;
};

