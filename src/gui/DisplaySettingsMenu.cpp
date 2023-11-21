#include "DisplaySettingsMenu.hpp"

//DisplaySettings Class

//Initializers

auto DisplaySettingsMenu::initButtons(sf::Font& font, sf::VideoMode resolution, u_short buttons_width, u_short character_size) -> void {
	auto buttonNames = std::vector<std::string>{
			"Resolution: ",
			"Full Screen: ",
			"Frame Rate Limit: ",
			"Vertical Sync: ",
			"Antialiasing Level: ",
			"Back",
			"Confirm"
	};
	auto offset = 45.f;
	auto tmp = sf::Text();
	tmp.setCharacterSize(character_size);
	for (int i = 0; i < buttonNames.size(); i++) {
		if (i < buttonNames.size() - 2) {
			tmp.setString(buttonNames[i]);
			this->buttons[buttonNames[i]] = new gui::Button(
				resolution.width / 4.f + (buttons_width / 3.f) - tmp.getGlobalBounds().width / 2.f, //pos_x
				200.f + (60 * i), //pos_y
				buttons_width, //width
				50.f, //height
				buttonNames[i], 16,
				sf::Color(0, 0, 0, 255),
				sf::Color(250, 250, 250, 250),
				sf::Color(20, 20, 20, 50),
				sf::Color(70, 70, 70, 0),
				sf::Color(150, 150, 150, 0),
				sf::Color(20, 20, 20, 0), this->stateData.font
			);
		}
		else if (i == buttonNames.size() - 2) {
			tmp.setString(buttonNames[i]);
			this->buttons[buttonNames[i]] = new gui::Button(
				resolution.width / 2.f - (buttons_width / 5.f) - tmp.getGlobalBounds().width / 2.f + offset, //pos_x
				200.f + (60 * i), //pos_y
				buttons_width, //width
				50.f, //height
				buttonNames[i], 16,
				sf::Color(0, 0, 0, 255),
				sf::Color(250, 250, 250, 250),
				sf::Color(20, 20, 20, 50),
				sf::Color(70, 70, 70, 0),
				sf::Color(150, 150, 150, 0),
				sf::Color(20, 20, 20, 0), this->stateData.font
			);
		}
		//Confirm Button
		else if (i == buttonNames.size() - 1) {
			tmp.setString(buttonNames[i]);
			this->buttons[buttonNames[i]] = new gui::Button(
				((resolution.width / 2.f - (buttons_width / 4.f) - tmp.getGlobalBounds().width / 2.f + buttons_width + offset + 10)), //pos_x
				200.f + (60 * (i - 1)), //pos_y
				buttons_width, //width
				50.f, //height
				buttonNames[i], 16,
				sf::Color(0, 0, 0, 255),
				sf::Color(250, 250, 250, 250),
				sf::Color(20, 20, 20, 50),
				sf::Color(70, 70, 70, 0),
				sf::Color(150, 150, 150, 0),
				sf::Color(20, 20, 20, 0), this->stateData.font
			);
		}

	}


}

auto DisplaySettingsMenu::initText(sf::Font& font, sf::VideoMode resolution) -> void {

	this->text.setFont(font);
	this->text.setFillColor(sf::Color::White);
	this->text.setString("Display Settings");
	this->text.setPosition(
		sf::Vector2f(
			resolution.width / 2.f - this->text.getGlobalBounds().width / 2.f,
			resolution.height / 2.f - (7 * this->text.getGlobalBounds().height)
		)
	);
}

auto DisplaySettingsMenu::initBackground(sf::VideoMode resolution) -> void {

	auto offset = 35.f;

	this->background.setSize(sf::Vector2f(resolution.width / 2.f, resolution.height / 2.f + (3 * offset)));
	this->background.setPosition(sf::Vector2f(resolution.width / 4.f, resolution.height / 4.f - 2 * offset));
	this->background.setFillColor(sf::Color(0, 0, 0, 100));

	this->transparentBackground.setSize(sf::Vector2f(resolution.width, resolution.height));
	this->transparentBackground.setPosition(0, 0);
	this->transparentBackground.setFillColor(sf::Color(215, 215, 215, 100));

}

//Constructors & Destructors
DisplaySettingsMenu::DisplaySettingsMenu(StateData& stateData, u_short buttons_width, u_short character_size, bool menu) :
	Menu(stateData, menu) {
	this->initButtons(stateData.font, stateData.gfxSettings->resolution, buttons_width, character_size);
	this->initText(stateData.font, stateData.gfxSettings->resolution);
	this->initBackground(stateData.gfxSettings->resolution);
}



//Update methods
auto DisplaySettingsMenu::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateButtons(dt, mouse_position);
}

auto DisplaySettingsMenu::updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->buttons["Confirm"]->update(dt, mouse_position);
	this->buttons["Back"]->update(dt, mouse_position);


	if (this->buttons["Confirm"]->isPressed());
	if (this->buttons["Back"]->isPressed()) this->menu = false;


}
//Render methods
auto DisplaySettingsMenu::render(sf::RenderTarget& target) -> void {
	this->renderBackground(target);
	this->renderButtons(target);
}

auto DisplaySettingsMenu::renderBackground(sf::RenderTarget& target)  -> void {
	target.draw(this->transparentBackground);
	target.draw(this->background);
	target.draw(this->text);
}

auto DisplaySettingsMenu::renderButtons(sf::RenderTarget& target) -> void {
	for (auto& it : this->buttons)
		it.second->render(target);


}