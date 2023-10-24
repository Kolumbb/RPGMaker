#include "stdafx.h"
#include "MainMenuState.h"




//Initializers

auto MainMenuState::initBackground() -> void {
	auto file = std::filesystem::path("..\\..\\..\\..\\Resources\\mainMenu\\background.png");

	assert(!file.empty());

	if (!this->texture.loadFromFile(file.string())) {
		this->shape.setFillColor(sf::Color::Red);
	} 
	this->shape.setTexture(&this->texture);
	this->shape.setSize(sf::Vector2f(this->stateData->gfxSettings.resolution.width, this->stateData->gfxSettings.resolution.height));
}

auto MainMenuState::initKeyBinds()-> void {
	auto file = std::fstream("..\\..\\..\\..\\Resources\\config\\key_binds_mainmenustate.ini");

	assert(file);

	if (file) {
		auto key = std::string();
		auto key_value = std::string();
		
		while (file >> key >> key_value) {
			this->keyBinds[key] = this->stateData->supportedKeys->at(key_value);
		}
	}
	file.close();
	//for (auto& it : this->keyBinds) std::cout << it.first << " " << it.second << std::endl;
}

auto MainMenuState::initButtons() -> void {

	auto btn_names = std::vector<std::string>();
	btn_names.push_back("New Game");
	btn_names.push_back("Settings");
	btn_names.push_back("Editor");
	btn_names.push_back("Quit");


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
MainMenuState::MainMenuState(StateData* state_data) :
	State(state_data) {
	this->initKeyBinds();
	this->initBackground();
	this->initButtons();

}

MainMenuState::~MainMenuState() {
	for (auto& it : this->buttons) {
		delete it.second;
		std::cout << "Button deleted\n";
	}
	
}

//Update methods
auto MainMenuState::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateKeyTime(dt);
	this->updateButtons(dt, mouse_position);
	this->updateKeyBindsInput(dt);
}

auto MainMenuState::updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void {
	for (auto& it : this->buttons) it.second->update(dt, mouse_position);


	if (this->buttons["New Game"]->isPressed() && this->getKeyTime(dt)) 
		this->stateData->states->push(new GameState(this->stateData));

	if (this->buttons["Settings"]->isPressed() && this->getKeyTime(dt))
		this->stateData->states->push(new SettingsState(this->stateData));

	if (this->buttons["Quit"]->isPressed() && this->getKeyTime(dt))
		while (!this->stateData->states->empty()) 
			this->stateData->states->pop();
}

auto MainMenuState::updateKeyBindsInput(const float& dt) -> void {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key((this->keyBinds["CLOSE"]))) && this->getKeyTime(dt))
		this->stateData->states->pop();
}

//Render methods

auto MainMenuState::render(sf::RenderTarget& target) -> void {
	target.draw(this->shape);
	this->renderButtons(target);
}


auto MainMenuState::renderButtons(sf::RenderTarget& target) -> void {
	for (auto& it : this->buttons) it.second->render(target);
}
