#pragma once

#include "../stdafx.hpp"

namespace gui {
	enum ButtonState { IDLE = 0, HOVER, PRESSED };
	class Button {
	private:

		//Variables & Resources
		sf::Text text;
		ButtonState btnState;
		sf::RectangleShape shape;
		sf::Vector2f size;
		sf::Vector2f position;

		sf::Color textIdleColor;
		sf::Color textHoverColor;
		sf::Color textActiveColor;

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;

		sf::Color outlineIdleColor;
		sf::Color outlineHoverColor;
		sf::Color outlineActiveColor;


		//Methods

		//Initializers
		auto initShape(float pos_x, float pos_y, float _width, float _height) -> void;
		auto initText(std::string _text, u_short character_size, sf::Font& _font) -> void;

		//Accessors

		auto updateBtnState() -> void;
		auto updateMousePosition(const float& dt, const sf::Vector2f& mouse_position) -> void;



	protected:

	public:

		auto isPressed() const -> bool const;

		//Constructors & Destructors
		Button(float pos_x, float pos_y, float _width, float _height,
			std::string _text, u_short character_size,
			sf::Color text_idle_color, sf::Color text_hover_color, sf::Color p_text_active_color,
			sf::Color idle_color, sf::Color hover_color, sf::Color active_color, sf::Font& _font,
			sf::Color outline_idle_color = sf::Color::Transparent, sf::Color outline_hover_color = sf::Color::Transparent, sf::Color outline_active_color = sf::Color::Transparent
		);
		~Button();
		//Methods
		auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
		auto render(sf::RenderTarget& target) const -> void const;

	};

	class DropDownList {

	};

}



