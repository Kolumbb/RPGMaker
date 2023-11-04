#pragma once
#include "Gui.hpp"
#include "StateData.hpp"



class State {
private:

	
	//Variables & Resources

	float keyTime;
	float keyTimeMax;
	
	//Private methods


protected:
	//Variables & Resources
	std::map<std::string, int> keyBinds;
	StateData* stateData;

	//Initializers
	virtual auto initKeyBinds() -> void = 0;
	
	//Accessors & Modifiers
	auto getKeyTime(const float& dt) -> bool const;
	


	auto updateKeyTime(const float& dt) -> void;
	virtual auto updateKeyBindsInput(const float& dt) -> void = 0;
public:
	//Constructors & Destructors
	State(StateData* state_data);
	virtual ~State();
	
	//Update methods
	virtual auto update(const float& dt, const sf::Vector2f& mouse_position) -> void = 0;

	//Render methods
	virtual auto render(sf::RenderTarget& target) -> void = 0;


};
