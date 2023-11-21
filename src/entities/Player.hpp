#pragma once

#include "Entity.hpp"
#include "../stdafx.hpp"




class Player : public Entity {
private:
	//Variables
	//Initializers
	
	auto initTexture(std::filesystem::path path) -> void;
	auto initSprite() -> void;
	auto initMovementComponent() -> void;
	auto initAnimationComponent() -> void;
	//Accessors & Modifiers
protected:
public:

	//Constructors & Destructors
	Player(const float pos_x, const float pos_y);
	~Player();

	//Uprade methods
	auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;

	//Render methods
	auto render(sf::RenderTarget& target) -> void;

	//Other methods
	auto move(const float& dt, const float x, const float y) -> void;
};