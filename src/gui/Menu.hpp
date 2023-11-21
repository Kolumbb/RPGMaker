#pragma once

#include "../stdafx.hpp"
#include "../StateData.hpp"
#include "Gui.hpp"

class Menu {
protected:
	
	StateData& stateData;
	bool menu;
	sf::Text text;
	sf::RectangleShape transparentBackground;
	sf::RectangleShape background;
	std::map<std::string, gui::Button*> buttons;

	//Initializers
	virtual auto initText(sf::Font& font, sf::VideoMode resolution) -> void = 0;
	virtual auto initBackground(sf::VideoMode resolution) -> void = 0;
	virtual auto initButtons(sf::Font& font, sf::VideoMode resolution, u_short buttons_width, u_short character_size) -> void = 0;

	//Update methods
	virtual auto updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void = 0;
	virtual auto update(const float& dt, const sf::Vector2f& mouse_position) -> void = 0;

	//Render methods
	virtual auto render(sf::RenderTarget& target) -> void = 0;
	virtual auto renderBackground(sf::RenderTarget& target) -> void = 0;
	virtual auto renderButtons(sf::RenderTarget& target) -> void = 0;


public:
	
	//Accessors & Modifiers
	auto getMenu() -> const bool const;
	auto setMenu(bool yn) -> void;
	Menu(StateData& state_data, bool menu);
	virtual ~Menu();
};