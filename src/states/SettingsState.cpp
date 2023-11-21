#include "SettingsState.hpp"




//Initializers
auto SettingsState::initBackground(
	std::filesystem::path path = "..\\..\\..\\..\\Resources\\mainMenu\\background.png"
	) -> void {

	this->background = std::make_unique<sf::RectangleShape>();
	if (!this->texture.loadFromFile(path.string())) {
		this->background->setFillColor(sf::Color::Red);
	}
	this->background->setTexture(&this->texture);
	this->background->setSize(
		sf::Vector2f(
			this->stateData.gfxSettings->resolution.width, 
			this->stateData.gfxSettings->resolution.height
		)
	);
}

auto SettingsState::initKeyBinds(
	std::filesystem::path path = "..\\..\\..\\..\\Resources\\config\\key_binds.settingsState.ini"
	) -> void {

	auto file = std::fstream(path);
	
	assert(file);

	if (file) {
		auto key = std::string();
		auto key_value = std::string();
		while (file >> key >> key_value) {
			this->keyBinds[key] = this->stateData.supportedKeys[key_value];
		}
	}
	file.close();
}

auto SettingsState::initButtons() -> void {
	auto btn_names = std::vector<std::string>();
	btn_names.push_back("Display Settings");
	btn_names.push_back("Controls");
	btn_names.push_back("Help");
	btn_names.push_back("Exit to Main Menu");

	for (int i = 0; i < btn_names.capacity(); i++) {
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
			sf::Color(20, 20, 20, 0), this->stateData.font
		);
	}

}

auto SettingsState::initDisplaySettingsMenu() -> void{
	this->dMenu = std::make_unique<DisplaySettingsMenu>(this->stateData, 150, 16);
}


//Constructors & Destructors
SettingsState::SettingsState(StateData& state_data) :
	State(state_data) {
	this->initDisplaySettingsMenu();
	this->initKeyBinds();
	this->initBackground();
	this->initButtons();

}

SettingsState::~SettingsState(){
	if (!this->buttons.empty()) {
		for (auto& it : this->buttons)
			delete it.second;
	}
	this->buttons.clear();
}




//Update Methods
auto SettingsState::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateKeyTime(dt);
	this->updateKeyBindsInput(dt);

	//Update unpaused
	if (!this->dMenu->getMenu()) {
		this->updateSettingsState(dt, mouse_position);
	}
	//Update paused
	else {
		this->updateDisplaySettings(dt, mouse_position);
	}
}

auto SettingsState::updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void {
	for (auto& it : this->buttons) it.second->update(dt, mouse_position);


	if (this->buttons.at("Display Settings")->isPressed() && this->getKeyTime(dt))
		this->dMenu->setMenu(true);

	if (this->buttons.at("Exit to Main Menu")->isPressed() && this->getKeyTime(dt)) {
		this->stateData.states.pop();
		
	}
	
}

auto SettingsState::updateKeyBindsInput(const float& dt) -> void {
	//Keybinds settings state
	if (!this->dMenu->getMenu()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds[ "CLOSE"])) && this->getKeyTime(dt))
			this->stateData.states.pop();
	}
}

//Update SettingsState
auto SettingsState::updateSettingsState(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateButtons(dt, mouse_position);

}

//Update DisplaySettings
auto SettingsState::updateDisplaySettings(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->dMenu->update(dt, mouse_position);

}



//Render methods
auto SettingsState::render(sf::RenderTarget& target) -> void {
	this->renderSettingsState(target);

	if (this->dMenu->getMenu())
		this->renderDisplaySettings(target);
}

auto SettingsState::renderButtons(sf::RenderTarget& target) -> void {
	for (auto& it : this->buttons) it.second->render(target);
}

//Render DisplaySettings
auto SettingsState::renderDisplaySettings(sf::RenderTarget& target) -> void {
	this->dMenu->render(target);
}

//Render SettingsState
auto SettingsState::renderSettingsState(sf::RenderTarget& target) -> void {
	target.draw(*this->background);
	this->renderButtons(target);
}




