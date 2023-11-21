#pragma once
#include "../stdafx.hpp"

class MovementComponent{
private:
	//Variables & Resources
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;


public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
	~MovementComponent() = default;

	//Accessors & Modifiers
	auto getMaxVelocity() -> const float&;

	//Other methods
	void move(const float x, const float y, const float& dt);
	void update(const float& dt);
};

