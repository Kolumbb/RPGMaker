#include "MovementComponent.hpp"


/*
	The idea of movement component is that we are taking an input from user in game state to move the entity sprite. By move function we are increasing the value of
	movement velocity by adding acceleration.
*/

//Accessors & Modifiers
auto MovementComponent::getMaxVelocity() -> const float& {
	return this->maxVelocity;
}

//Constructors & Destructors
MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration): 
	velocity(sf::Vector2f{0, 0}), sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration) {
}



//Update methods
void MovementComponent::update(const float& dt) {
	
	/*
		When none of buttons are pressed, force of deceleration decreses velocity, 
		so that the entity would not move in infinite time. Also creating bounds over 
		acceleration to keep velocity in check.
		At the end moves the sprite with the achieved velocity 
	*/

	//Left & Rignt bounds
	if (this->velocity.x > 0.f) {
		//Acceleration
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//Deceleration
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else {
		//Acceleration
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//Deceleration
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	//Up & Down bounds
	if (this->velocity.y > 0.f) {
		//Acceleration
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//Deceleration
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else {
		//Acceleration
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//Deceleration
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}
	

	this->sprite.move(this->velocity * dt);
}

//Other methods
void MovementComponent::move(const float x, const float y, const float& dt){
	
	//Increase velocity after button press
	
	this->velocity.x += this->acceleration * x;
	this->velocity.y += this->acceleration * y;

}


