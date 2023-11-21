#pragma once
#include "../stdafx.hpp"
#include "../components/MovementComponent.hpp"
#include "../components/AnimationComponent.hpp"

class Entity {
protected:
	//Variables & Resources
	std::shared_ptr<sf::Texture> texture;
	std::shared_ptr<sf::Sprite> sprite;
	sf::RectangleShape shape;
	std::shared_ptr<MovementComponent> movementComponent;
	std::shared_ptr<AnimationComponent> animationComponent;

	//Initializers
	virtual auto initMovementComponent() -> void = 0;
	virtual auto initTexture(std::filesystem::path path) -> void = 0;
	virtual auto initSprite() -> void = 0;
public:
	//Constructors & Destructors
	Entity();
	virtual ~Entity();

	//Update methods
	virtual auto update(const float& dt, const sf::Vector2f& mouse_position) -> void = 0;

	//Render methods
	virtual auto render(sf::RenderTarget& target) -> void = 0;

	//Other methods
	virtual auto move(const float& dt, const float x, const float y) -> void = 0;
};