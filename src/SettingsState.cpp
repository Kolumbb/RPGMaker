#include "stdafx.h"
#include "SettingsState.h"

auto SettingsState::initBackground() -> void {
	auto path = std::filesystem::path("..\\..\\..\\..\\Resources\\mainMenu\\background.png");
	if (!this->texture.loadFromFile(path.string())) {
		MessageBox(HWND(), "Sorry, we couldn't find one of your main menu assets, please check the file location", "Error", MB_ICONWARNING);
		this->shape.setFillColor(sf::Color::Red);
	}
	this->shape.setTexture(&this->texture);
	this->shape.setSize(sf::Vector2f(this->stateData->gfxSettings.resolution.width, this->stateData->gfxSettings.resolution.height));
}

auto SettingsState::initKeyBinds() -> void {
	auto path = std::filesystem::path("..\\..\\..\\..\\Resources\\config\\key_binds.settingsState.ini");
	std::ifstream ifs(path);
	if (ifs.is_open()) {
		auto key = std::string();
		auto key_value = std::string();
		while (ifs >> key >> key_value) {
			this->keyBinds[key] = this->stateData->supportedKeys->at(key_value);
		}
		ifs.close();
	}
	else MessageBox(HWND(), "Sorry, we couldn't find your supported keys configuration, please check the file location", "Error", MB_ICONWARNING);
	ifs.close();
	for (auto& it : this->keyBinds) std::cout << it.first << " " << it.second << std::endl;
}

auto SettingsState::initButtons() -> void {

	auto btn_names = std::vector<std::string>();
	
	btn_names.push_back("Display Settings");
	btn_names.push_back("Controls");
	btn_names.push_back("Help");
	btn_names.push_back("Exit to Main Menu");


	auto tmp = sf::Text();
	tmp.setCharacterSize(16);

	for (int i = 0; i < btn_names.capacity(); i++) {
		tmp.setString(btn_names[i]);
		this->buttons[btn_names[i]] = new gui::Button(
			100.f, //pos_x
			(400.f + (60 * i)), //pos_y
			150.f, //width
			50.f, //height
			btn_names[i], 16,
			sf::Color(0, 0, 0, 255),
			sf::Color(250, 250, 250, 250),
			sf::Color(20, 20, 20, 50),
			sf::Color(70, 70, 70, 0),
			sf::Color(150, 150, 150, 0),
			sf::Color(20, 20, 20, 0), this->stateData->font
		);
	}

}

//Accessors & Modifiers

//Constructors & Destructors
SettingsState::SettingsState(StateData* state_data) :
	State(state_data) {
	this->initKeyBinds();
	this->initBackground();
	this->initButtons();

}

SettingsState::~SettingsState() {
	for (auto& it : this->buttons) {
		delete it.second;
		std::cout << "Button deleted\n";
	}

}

//Update methods
auto SettingsState::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateKeyTime(dt);
	this->updateButtons(dt, mouse_position);
	this->updateKeyBindsInput(dt);
}

auto SettingsState::updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void {
	for (auto& it : this->buttons) it.second->update(dt, mouse_position);

	if(this->buttons.at("Exit to Main Menu")->isPressed() && this->getKeyTime(dt))
		this->stateData->states->pop();

		

		
}

auto SettingsState::updateKeyBindsInput(const float& dt) -> void {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key((this->keyBinds["CLOSE"]))) && this->getKeyTime(dt))
		this->stateData->states->pop();
	
}

//Render methods

auto SettingsState::render(sf::RenderTarget& target) -> void {
	target.draw(this->shape);
	this->renderButtons(target);
}


auto SettingsState::renderButtons(sf::RenderTarget& target) -> void {
	for (auto& it : this->buttons) it.second->render(target);
}