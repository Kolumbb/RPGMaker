#pragma once

#include "../stdafx.hpp"
#include "Menu.hpp"
#include "Gui.hpp"


class DisplaySettingsMenu : public Menu {
protected:
	//Initializers
	auto initText(sf::Font& font, sf::VideoMode resolution) -> void;
	auto initBackground(sf::VideoMode resolution) -> void;
	auto initButtons(sf::Font& font, sf::VideoMode resolution, u_short buttons_width, u_short character_size) -> void;
	

public:


	//Constructors & Destructors
	DisplaySettingsMenu(StateData& stateData, u_short buttons_width, u_short character_size, bool menu = false);
	~DisplaySettingsMenu() = default;

	//Public methods

	//Modifiers
	//Update methods
	auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
	auto updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void;

	//Render methods
	auto render(sf::RenderTarget& target) -> void;
	auto renderBackground(sf::RenderTarget& target) -> void;
	auto renderButtons(sf::RenderTarget& target) -> void;
};
