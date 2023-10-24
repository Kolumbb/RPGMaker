#include "stdafx.h"
#include "Game.h"

//Private methods

auto Game::getQuit() -> bool const
{
	return this->quit;
}

//Initializers
auto Game::initSupportedKeys() -> void{

	auto key = std::string();
	auto key_value = int();


	//Filling supportedKeys map with pairs from file
	auto file = std::fstream("..\\..\\..\\..\\Resources\\Config\\supported_keys.ini");
	
	assert(file);
	
	if (file) {
		while (file >> key >> key_value)
			this->stateData.supportedKeys->emplace(std::pair<std::string, int>(key, key_value));
	}
	file.close();

}

auto Game::initStateData() -> void{
	this->initFont();
	this->initGfxSettings();

}

auto Game::initGfxSettings() ->void{
	auto path = std::filesystem::path("..\\..\\..\\..\\Resources\\Config\\display_settings.ini");

	assert(!path.empty());
	this->stateData.gfxSettings.loadFromFile(path);

}

auto Game::initFont() -> void{
	auto path = std::filesystem::path("..\\..\\..\\..\\Resources\\Fonts\\OpenSans-Regular.ttf");

	assert(!path.empty());
	this->stateData.font.loadFromFile(path.string());
		
}

auto Game::initStates() -> void{
	this->stateData.states->push(new MainMenuState(&this->stateData));

}

auto Game::initWindow() -> void{
	this->window = std::make_unique<sf::RenderWindow>(this->stateData.gfxSettings.resolution, this->stateData.gfxSettings.title, this->stateData.gfxSettings.fullScreen, this->stateData.gfxSettings.contextSettings);
}

//Constructors & Destructors
Game::Game() {
	this->initSupportedKeys();
	this->initStateData();
	this->initStates();
	this->initWindow();

	this->dt = float();
	this->quit = true;
}

Game::~Game() {
	while (!this->stateData.states->empty()) {
		this->stateData.states->pop();
		std::cout << "State poped\n";
	}
	this->window.release();
	delete this->window.get();
}

//Update methods
auto Game::update(const float& dt, const sf::Vector2f& mouse_position) -> void{
	this->updateEvents();
	if (!this->stateData.states->empty()) {
		this->stateData.states->top()->update(dt, mouse_position);
		
	}else this->quit = false;
}

auto Game::updateEvents() -> void {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) this->window->close();
		if (this->event.type == sf::Event::MouseMoved) this->mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->window));
	}
}

auto Game::updateDt() -> void{
	this->dt = this->clock.getElapsedTime().asSeconds();
	this->clock.restart();
}

//Render methods
auto Game::render(sf::RenderTarget* target) -> void{
	target = this->window.get();
	if (target) {
		this->window->clear();

		if (!this->stateData.states->empty())
			this->stateData.states->top()->render(*target);

		this->window->display();
	}
}



auto Game::run() -> void{
	while (this->window->isOpen() && this->getQuit()) {
		this->updateDt();
		this->update(this->dt, this->mousePosition);
		this->render(this->window.get());
	}
}
