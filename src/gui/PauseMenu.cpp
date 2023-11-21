#include "PauseMenu.hpp"


//Initializers


auto PauseMenu::initButtons(sf::Font& font, sf::VideoMode resolution, u_short buttons_width, u_short character_size) -> void {
	auto buttonNames = std::vector<std::string>{"Resume", "Save", "Load", "Quit"};

	auto tmp = sf::Text();
	tmp.setCharacterSize(character_size);

	for (int i = 0; i < buttonNames.size(); i++) {
		
		tmp.setString(buttonNames[i]);
		this->buttons[tmp.getString()] = new gui::Button(
			resolution.width / 2.f - (buttons_width / 2.f) - tmp.getGlobalBounds().width / 2.f, //pos_x
			400.f + (60 * i), //pos_y
			buttons_width, //width
			50.f, //height
			buttonNames[i], character_size,
			sf::Color(0, 0, 0, 255),
			sf::Color(250, 250, 250, 250),
			sf::Color(20, 20, 20, 50),
			sf::Color(70, 70, 70, 0),
			sf::Color(150, 150, 150, 0),
			sf::Color(20, 20, 20, 0), font
		);
	}
}

auto PauseMenu::initText(sf::Font& font, sf::VideoMode resolution) -> void {
	this->text.setFont(font);
	this->text.setFillColor(sf::Color::White);
	this->text.setString("PAUSED");
	this->text.setPosition(
		sf::Vector2f(
			resolution.width / 2 - this->text.getGlobalBounds().width / 2.f,
			100
		)
	);
}

auto PauseMenu::initBackground(const sf::VideoMode resolution) -> void {
	this->background.setSize(sf::Vector2f(resolution.width / 2.f, resolution.height));
	this->background.setPosition(sf::Vector2f(resolution.width / 4.f, 0));
	this->background.setFillColor(sf::Color(0, 0, 0, 100));

	this->transparentBackground.setSize(sf::Vector2f(resolution.width, resolution.height));
	this->transparentBackground.setPosition(0, 0);
	this->transparentBackground.setFillColor(sf::Color(215, 215, 215, 100));

}

//Constructors & Destructors

//
PauseMenu::PauseMenu(StateData& state_data, u_short buttons_width, u_short character_size, bool menu) : Menu(state_data, menu) {
	this->initButtons(state_data.font, stateData.gfxSettings->resolution, buttons_width, character_size);
	this->initText(state_data.font, stateData.gfxSettings->resolution);
	this->initBackground(state_data.gfxSettings->resolution);

}


//Update methods
auto PauseMenu::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateButtons(dt, mouse_position);
}

auto PauseMenu::updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void {
	for (auto& it : this->buttons)
		it.second->update(dt, mouse_position);

	if (this->buttons["Resume"]->isPressed()) this->menu = false;
	if (this->buttons["Quit"]->isPressed())this->stateData.states.pop();
}

//Render methods
auto PauseMenu::render(sf::RenderTarget& target) -> void {
	this->renderBackground(target);
	this->renderButtons(target);
}

auto PauseMenu::renderBackground(sf::RenderTarget& target)  -> void {
	target.draw(this->transparentBackground);
	target.draw(this->background);
	target.draw(this->text);
}

auto PauseMenu::renderButtons(sf::RenderTarget& target) -> void {
	for(auto & it : this->buttons)
		it.second->render(target);
}