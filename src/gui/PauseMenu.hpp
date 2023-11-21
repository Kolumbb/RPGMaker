#pragma once

#include "../stdafx.hpp"
#include "Menu.hpp"
#include "Gui.hpp"
#include "../StateData.hpp"


class PauseMenu : public Menu {
	private:
		//Variables & Resources

	protected:
		//Initializers
		auto initText(sf::Font& font, sf::VideoMode resolution) -> void;
		auto initBackground(sf::VideoMode resolution) -> void;
		auto initButtons(sf::Font& font, sf::VideoMode resolution, u_short buttons_width, u_short character_size) -> void;
		auto updateButtons(float& dt, sf::Vector2f& mouse_position) -> void;

	public:

		//Constructors & Destructors
		PauseMenu(StateData& state_data, u_short buttons_width, u_short character_size, bool menu = false);
		virtual ~PauseMenu() = default;

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
