#pragma once
class MovementComponent{
private:

	//Resources & Variables
	sf::Sprite* sprite;
	sf::Vector2f& velocity;
	float maxVelocity;
	float acceleration;
	float deceleration;



	//Initializers

protected:
public:
	
	//Constructors & Destructors
	MovementComponent(sf::Sprite* _sprite, sf::Vector2f& _velocity, float _acceleration, float _deceleration, float max_velocity);
	~MovementComponent();

	//Update methods
	 auto update(const float& dt, Direction dir = IDLE) -> sf::Vector2f const;
};

