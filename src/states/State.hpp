#pragma once
#include "../stdafx.hpp"
#include "../gui/Gui.hpp"
#include "../StateData.hpp"

/*
	The idea is that the game has different states where player can do 
	different things and where resources would be placed. Every time when you
	enter new state you will play only with those solutions that have 
	been designed for a given state. That prevents from loading all resources
	at the same time when the game starts.
*/

class State {
private:
	//Private Variables & Resources
	float keyTime;
	float keyTimeMax;

protected:

	//Protected Variables & Resources
	std::map<std::string, int> keyBinds;
	StateData& stateData;
	sf::Texture texture;
	
	//Protected Initializers
	virtual auto initKeyBinds(std::filesystem::path path) -> void = 0;
	
	//Protected Accessors & Modifiers
	auto getKeyTime(const float& dt) -> bool const;

	//Protected Update methods
	auto updateKeyTime(const float& dt) -> void;

public:
	//Constructors & Destructors
	State(StateData& state_data);
	virtual ~State();
	
	//Public Update methods
	virtual auto update(const float& dt, const sf::Vector2f& mouse_position) -> void = 0;

	//Public Render methods
	virtual auto render(sf::RenderTarget& target) -> void = 0;


};
