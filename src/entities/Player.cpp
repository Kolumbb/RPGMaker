#include "Player.hpp"



//Initializers
auto Player::initMovementComponent() -> void {
	this->movementComponent = std::make_shared<MovementComponent>(*this->sprite, 220.f, 5.f, 3.f);
}

auto Player::initAnimationComponent() -> void{
	this->animationComponent = std::make_shared<AnimationComponent>(*this->sprite, *this->texture);

	this->animationComponent->addAnimation("IDLE_LEFT", 50.f, 0, 0, 15, 0, 144, 96);
	this->animationComponent->addAnimation("WALK_LEFT", 50.f, 0, 1, 7, 1, 144, 96);
	this->animationComponent->addAnimation("ATTACK_FULL_COMBO", 50.f, 0, 2, 21, 2, 144, 96);
	this->animationComponent->addAnimation("ATTACK_LONG_SWING", 50.f, 0, 4, 15, 4, 144, 96);
	this->animationComponent->addAnimation("HURT", 50.f, 0, 5, 7, 5, 144, 96);
	this->animationComponent->addAnimation("DEATH", 50.f, 0, 6, 18, 6, 144, 96);
}

auto Player::initTexture(
	std::filesystem::path path = "..\\..\\..\\..\\Resources\\gameState\\warrior.png"
	) -> void {
	this->texture = std::make_shared<sf::Texture>();
	this->texture->loadFromFile(path.string());
}

auto Player::initSprite() -> void{
	this->sprite = std::make_shared<sf::Sprite>();
	this->sprite->setTexture(*this->texture);
}

//Constructors & Destructors
Player::Player(const float pos_x, const float pos_y){
	this->initTexture();
	this->initSprite();
	this->initMovementComponent();
	this->initAnimationComponent();
	this->sprite->setPosition(100, 100);

}

Player::~Player() {

}

auto Player::update(const float& dt, const sf::Vector2f& mouse_position) -> void {
	this->movementComponent->update(dt);
	this->animationComponent->play("DEATH", dt);
}

auto Player::render(sf::RenderTarget& target) -> void {
	target.draw(*this->sprite);

}

//Other methods
auto Player::move(const float& dt, const float x, const float y) -> void {
	this->movementComponent->move(x, y, dt);
}