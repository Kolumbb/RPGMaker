#pragma once

#include "stdafx.hpp"

class Animation {
private:
	//Variables & Resources
	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	float speed;
	float animationTimer;
	float timer;
	u_short textureWidth;
	u_short textureHeight;
	sf::IntRect startRect;
	sf::IntRect currentRect;
	sf::IntRect endRect;
	
	//Initializers
	auto initSprite(sf::IntRect startRect) -> void;

public:

	//Constructors & Destructors
	Animation(
		sf::Sprite& sprite, sf::Texture& textureSheet,
		float animationTimer, u_short startFrameX, u_short startFrameY,
		u_short framesX, u_short framesY, u_short textureWidth, u_short textureHeight
	);
	

	~Animation() = default;

	//Update methods

	//Other public methods
	auto play(const float& dt) -> void;
	auto pause() -> void;
	auto reset() -> void;
};

