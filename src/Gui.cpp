#include "stdafx.h"
#include "Gui.h"




//Pause Menu class

//Private methods

//Initializers


auto gui::PauseMenu::initButtons(const StateData* state_data, u_short buttons_width, u_short character_size) -> void{

	std::vector<std::string> names;
	names.push_back("Resume");
	names.push_back("Save");
	names.push_back("Load");
	names.push_back("Quit");



	this->text.setCharacterSize(character_size);
	this->text.setFont(state_data->font);

	sf::Text tmp;
	for (int i = 0; i < names.capacity(); i++) {
		tmp.setString(names[i]);
		
		this->buttons[names[i]] =new gui::Button(
			state_data->gfxSettings.resolution.width / 2.f - (buttons_width / 2.f) - tmp.getGlobalBounds().width / 2.f, //pos_x
			400.f + (60 * i), //pos_y
			buttons_width, //width
			50.f, //height
			names[i], character_size,
			sf::Color(0, 0, 0, 255),
			sf::Color(250, 250, 250, 250),
			sf::Color(20, 20, 20, 50),
			sf::Color(70, 70, 70, 0),
			sf::Color(150, 150, 150, 0),
			sf::Color(20, 20, 20, 0), this->font
		);
	}	
}

auto gui::PauseMenu::initText(const StateData* state_data) -> void {
	this->text.setString("PAUSED");
	this->text.setFont(state_data->font);
	this->text.setCharacterSize(32);
	this->text.setPosition(
		sf::Vector2f(
			state_data->gfxSettings.resolution.width / 2 - this->text.getGlobalBounds().width /2.f,
			200
		)
	);
	this->text.setFillColor(sf::Color::White);
}

auto gui::PauseMenu::initBackground(const StateData* state_data) -> void{
	this->background.setSize(sf::Vector2f(state_data->gfxSettings.resolution.width / 2.f, state_data->gfxSettings.resolution.height));
	this->background.setPosition(sf::Vector2f(state_data->gfxSettings.resolution.width / 4.f, 0));
	this->background.setFillColor(sf::Color(0, 0, 0, 100));
	this->transparentBackground.setSize(sf::Vector2f(state_data->gfxSettings.resolution.width, state_data->gfxSettings.resolution.height));
	this->transparentBackground.setPosition(0, 0);
	this->transparentBackground.setFillColor(sf::Color(215, 215, 215, 100));

}

//Constructors & Destructors
gui::PauseMenu::PauseMenu(const StateData* state_data, u_short buttons_width, u_short character_size, bool& _paused):
	font(state_data->font), paused(_paused), states(*state_data->states){

	this->initBackground(state_data);
	this->initButtons(state_data, buttons_width, character_size);
	this->initText(state_data);
	
}

gui::PauseMenu::~PauseMenu() {

}


//Public methods

//Update methods
auto gui::PauseMenu::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateButtons(dt, mouse_position);
}

auto gui::PauseMenu::updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void {
	for (auto& it : this->buttons) it.second->update(dt, mouse_position);
	if (this->buttons["Resume"]->isPressed()) this->paused = false;
	if (this->buttons["Quit"]->isPressed())this->states.pop();
}
//Render methods
auto gui::PauseMenu::render(sf::RenderTarget& target) -> void {
	this->renderBackground(target);
	this->renderButtons(target);
}

auto gui::PauseMenu::renderBackground(sf::RenderTarget& target)  -> void {
	target.draw(this->transparentBackground);
	target.draw(this->background);
	target.draw(this->text);
}

auto gui::PauseMenu::renderButtons(sf::RenderTarget& target) -> void {
	for (auto& it : this->buttons) it.second->render(target);
}

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
auto gui::Button::isPressed() -> bool const{
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

gui::Button::~Button(){

}

//Public Methods

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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) this->btnState = PRESSED;
	}
}

//Render methods
auto gui::Button::render(sf::RenderTarget& target) -> void {
	target.draw(this->shape);
	target.draw(this->text);
}



