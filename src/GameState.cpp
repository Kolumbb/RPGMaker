#include "stdafx.h"
#include "GameState.h"


//Private methods

//Initializers

auto GameState::initBackground() -> void {
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
}

auto GameState::initKeyBinds() -> void {
	auto file = std::fstream("..\\..\\..\\..\\Resources\\Config\\key_binds_gamestate.ini");
	
	if (file) {
		auto key = std::string();
		auto key_value = std::string();

		while (file >> key >> key_value) {
			this->keyBinds[key] = this->stateData->supportedKeys->at(key_value);
		}
	}
	else MessageBox(HWND(), "Sorry, we couldn't find your supported keys configuration, please check the file location", "Error", MB_ICONWARNING);
	file.close();
	for (auto& it : this->keyBinds) std::cout << it.first << " " << it.second << std::endl;
}

auto GameState::initPausedMenu() -> void {
	this->pMenu = new gui::PauseMenu(this->stateData, 150, 16, this->paused);
}

 auto GameState::initPlayer() -> void {
	this->player = new Player(200, 200, this->keyBinds);
}

//Accessors & Modifiers
auto GameState::getPaused() -> bool {
	return this->paused;
}

auto GameState::setPaused(bool yn) -> void {
	this->paused = yn;
}

GameState::GameState(StateData* state_data) : State(state_data), paused(false) {
	this->initKeyBinds();
	this->initBackground();
	this->initPlayer();
	this->initPausedMenu();
}

GameState::~GameState() {
	delete this->pMenu;
	delete this->player;

}

auto GameState::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateKeyTime(dt);
	if(!this->getPaused())
	this->updateUnPaused(dt, mouse_position);

	if (this->getPaused())
		this->updatePaused(dt, mouse_position);

}

//Update Paused
auto GameState::updateUnPaused(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateKeyBindsInput(dt);
	this->player->update(dt, mouse_position);

}

auto GameState::updateKeyBindsInput(const float& dt) -> void {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["CLOSE"])) && this->getKeyTime(dt)) this->setPaused(!this->getPaused());
}


//Update Unpaused
auto GameState::updatePaused(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->pMenu->update(dt, mouse_position);
	this->updateKeyBindsInput(dt);

}

auto GameState::render(sf::RenderTarget& target) -> void {
	this->renderUnPaused(target);

	if (this->getPaused())
		this->renderPaused(target);
}
auto GameState::renderPaused(sf::RenderTarget& target) -> void {
	this->pMenu->render(target);
	
}

auto GameState::renderUnPaused(sf::RenderTarget& target) -> void {
	if(player) player->render(target);
	
}