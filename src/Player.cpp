#include "stdafx.hpp"
#include "Player.hpp"

void Player::initStartRect(){
	this->startRect = sf::IntRect(0, 0, 144, 96);
	this->sprite.setTextureRect(startRect);
	this->sprite.setPosition(this->position);
}



void Player::initMovementComponent(){
	this->movementComponent = new MovementComponent(&this->sprite, this->velocity, 70, 30, 200);
}





Player::Player(float pos_x, float pos_y, std::map<std::string, int>& key_binds): Entity(pos_x, pos_y), keyBinds(key_binds){
	auto path = std::filesystem::path("..\\..\\..\\..\\Resources\\gameState\\warrior-all-animations-from top to bottom(Idle-run-full combo attack with 3 swings-single swing 1-single swing 3-hurt-death)-canvas 144x96.png");
	
	assert(!path.empty());
	this->textureSheet.loadFromFile(path.string());
	this->sprite.setTexture(this->textureSheet);
	this->initStartRect();
	this->initMovementComponent();


}

Player::~Player() {
	delete this->movementComponent;
}


void Player::update(const float& dt, const sf::Vector2f& mouse_position){
	this->updateUserInput(dt);
}

void Player::updateUserInput(const float& dt){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["MOVE_RIGHT"]))) {
		this->velocity = this->movementComponent->update(dt, this->direction = Direction::RIGHT);
		this->sprite.move(this->velocity);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["MOVE_LEFT"]))){
		this->velocity = this->movementComponent->update(dt, this->direction = Direction::LEFT);
		this->sprite.move(this->velocity);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["MOVE_UP"]))) {
		this->velocity = this->movementComponent->update(dt, this->direction = Direction::UP);
		this->sprite.move(this->velocity);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["MOVE_DOWN"]))) {
		this->velocity = this->movementComponent->update(dt, this->direction = Direction::DOWN);
		this->sprite.move(this->velocity);
	}
	if (isAnyKeyPressed() == false) {
		this->velocity = this->movementComponent->update(dt);
		this->sprite.move(this->velocity);
	}
}

void Player::render(sf::RenderTarget& target) {
	target.draw(this->sprite);
}