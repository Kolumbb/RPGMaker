#include "stdafx.h"
#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite* _sprite, sf::Vector2f& _velocity, float _acceleration, float _deceleration, float max_velocity) :
	velocity(_velocity), acceleration(_acceleration), deceleration(_deceleration), maxVelocity(max_velocity) {
	this->sprite = new sf::Sprite();
	this->sprite = _sprite;

}

MovementComponent::~MovementComponent(){
	delete this->sprite;
}

//Update methods
auto MovementComponent::update(const float& dt, Direction dir) -> sf::Vector2f const{




	switch (dir) {
		case IDLE: {
			if (this->velocity.x > 0) {
				this->velocity.x -= this->deceleration;
				if ((this->velocity.x - this->deceleration * dt) < 0) {
					this->velocity.x = 0;
				}
			}
			else {
				this->velocity.x += this->deceleration;
				if ((this->velocity.x + this->deceleration * dt) > 0) {
					this->velocity.x = 0;
				}
			}
			if (this->velocity.y > 0) {
				this->velocity.y -= this->deceleration;
				if ((this->velocity.y - this->deceleration * dt) < 0) {
					this->velocity.y = 0;
				}
			}
			else {
				this->velocity.y += this->deceleration;
				if ((this->velocity.y + this->deceleration * dt) > 0) {
					this->velocity.y = 0;
				}
			}
			this->sprite->move(this->velocity * dt);
		}break;
		case LEFT: {
			this->velocity.y = 0.f;
			this->velocity.x -= this->acceleration;
			if (this->velocity.x < -this->maxVelocity) this->velocity.x = -this->maxVelocity;
			this->sprite->move(this->velocity * dt);
		}break;
		case RIGHT: {
			this->velocity.y = 0.f;
			this->velocity.x += this->acceleration;
			if (this->velocity.x > this->maxVelocity) this->velocity.x = this->maxVelocity;
			this->sprite->move(this->velocity * dt);
		}break;
		case UP: {
			this->velocity.x = 0.f;
			this->velocity.y -= this->acceleration;
			if (this->velocity.y < -this->maxVelocity) this->velocity.y = -this->maxVelocity;
			this->sprite->move(this->velocity * dt);
		}break;
		case DOWN: {
			this->velocity.x = 0.f;
			this->velocity.y += this->acceleration;
			if (this->velocity.y > this->maxVelocity) this->velocity.y = this->maxVelocity;
			this->sprite->move(this->velocity * dt);
		}break;
		default: {
			
		}
	}

	
	return sf::Vector2f(this->velocity.x * dt, this->velocity.y * dt);
}
