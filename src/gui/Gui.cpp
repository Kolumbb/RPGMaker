#include "Gui.hpp"


//Button class

//Initializers
auto gui::Button::initShape(float pos_x, float pos_y, float _width, float _height) -> void {
	this->shape.setPosition(sf::Vector2f(pos_x, pos_y));
	this->shape.setSize(sf::Vector2f(sf::Vector2f(_width, _height)));
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(this->outlineIdleColor);
	this->shape.setFillColor(this->idleColor);
}

auto gui::Button::initText(std::string _text, u_short character_size, sf::Font& _font) -> void {
	this->text.setFont(_font);
	this->text.setString(_text);
	this->text.setCharacterSize(character_size);
	this->text.setFillColor(this->textIdleColor);
	this->text.setPosition(
		sf::Vector2f(
			this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
			this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f - this->text.getGlobalBounds().height / 2.f
		)
	);
}

//Accessors
auto gui::Button::isPressed() const -> bool const {
	if (this->btnState == PRESSED) return true;
	return false;
}

//Constructors & Destructors
gui::Button::Button(float pos_x, float pos_y, float _width, float _height,
	std::string _text, u_short character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color p_text_active_color,
	sf::Color idle_color, sf::Color hover_color, sf::Color active_color, sf::Font& _font,
	sf::Color outline_idle_color, sf::Color outline_hover_color, sf::Color outline_active_color
) :

	size(sf::Vector2f(pos_x, pos_y)), position(sf::Vector2f(_width, _height)),
	textIdleColor(text_idle_color), textHoverColor(text_hover_color), textActiveColor(p_text_active_color),
	idleColor(idle_color), hoverColor(hover_color), activeColor(active_color),
	outlineIdleColor(outline_idle_color), outlineHoverColor(outline_hover_color), outlineActiveColor(outline_active_color)
{
	this->initShape(pos_x, pos_y, _width, _height);
	this->initText(_text, character_size, _font);
}

gui::Button::~Button() {

}

//Update methods
auto gui::Button::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateMousePosition(dt, mouse_position);
	this->updateBtnState();
}

auto gui::Button::updateBtnState() -> void {
	switch (this->btnState) {
	case IDLE: {
		this->shape.setFillColor(this->idleColor);
		this->shape.setOutlineColor(this->outlineIdleColor);
		this->text.setFillColor(this->textIdleColor);
	}
			 break;
	case HOVER: {
		this->shape.setFillColor(this->hoverColor);
		this->shape.setOutlineColor(this->outlineHoverColor);
		this->text.setFillColor(this->textHoverColor);
	}
			  break;
	case PRESSED: {
		this->shape.setFillColor(this->activeColor);
		this->shape.setOutlineColor(this->outlineActiveColor);
		this->text.setFillColor(this->textActiveColor);
	}
				break;
	default: {
		this->shape.setFillColor(sf::Color::Red);
		this->shape.setOutlineColor(sf::Color::Green);
		this->text.setFillColor(sf::Color::Blue);
	}
		   break;
	}

}

auto gui::Button::updateMousePosition(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->btnState = IDLE;
	if (this->shape.getGlobalBounds().contains(mouse_position)) {
		this->btnState = HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->btnState = PRESSED;
	}
}

//Render methods
auto gui::Button::render(sf::RenderTarget& target) const -> void const{
	target.draw(this->shape);
	target.draw(this->text);
}

