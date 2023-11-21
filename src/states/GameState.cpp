#include "GameState.hpp"


//Initializers
auto GameState::initKeyBinds(
	std::filesystem::path path = "..\\..\\..\\..\\Resources\\Config\\key_binds_gamestate.ini"
	) -> void {

	auto file = std::fstream(path);

	if (file) {
		auto key = std::string();
		auto key_value = std::string();

		while (file >> key >> key_value) {
			this->keyBinds[key] = this->stateData.supportedKeys[key_value];
		}
	}
	file.close();



}

auto GameState::initPlayer(float pos_x, float pos_y){
	this->player = std::make_unique<Player>(pos_x, pos_y);
}

auto GameState::initPausedMenu() -> void {
	this->pMenu = std::make_unique<PauseMenu>(this->stateData, 150, 16);

}

auto GameState::makeFullScreen() -> void{
	
	//To do in the future
}



//Accessors & Modifiers


GameState::GameState(StateData& state_data) : State(state_data) {
	this->initKeyBinds();
	this->initPlayer(200, 200);
	this->initPausedMenu();
	this->makeFullScreen();
}



auto GameState::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->updateKeyTime(dt);
	this->updateKeyBindsInput(dt);


	//Update unpaused
	if(!this->pMenu->getMenu()){
		this->updateUnPaused(dt, mouse_position);
	}
	//Update paused
	else {
		this->updatePaused(dt, mouse_position);
	}
}

//Update Unpaused
auto GameState::updateUnPaused(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->player->update(dt, mouse_position);
	this->updateUserInput(dt, mouse_position);

}

auto GameState::updateUserInput(const float& dt, const sf::Vector2f& mouse_position) -> void {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["MOVE_RIGHT"])))
		this->player->move(dt, 1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["MOVE_LEFT"])))
		this->player->move(dt, -1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["MOVE_UP"])))
		this->player->move(dt, 0, -1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["MOVE_DOWN"])))
		this->player->move(dt, 0, 1);
}

//Update Paused
auto GameState::updatePaused(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->pMenu->update(dt, mouse_position);

}



auto GameState::updateKeyBindsInput(const float& dt) -> void {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["CLOSE"])) && this->getKeyTime(dt))
		this->pMenu->setMenu(!this->pMenu->getMenu());

}

//Render methods
auto GameState::render(sf::RenderTarget& target) -> void {
	this->renderUnPaused(target);
	this->player->render(target); 
	if (this->pMenu->getMenu())
		this->renderPaused(target);
}

auto GameState::renderPaused(sf::RenderTarget& target) -> void {
	this->pMenu->render(target);
	
}

auto GameState::renderUnPaused(sf::RenderTarget& target) -> void {

	
}