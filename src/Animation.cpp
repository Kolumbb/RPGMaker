#include "Animation.hpp"



//Initializers
auto Animation::initSprite(sf::IntRect startRect) -> void {
	this->sprite.setTexture(this->textureSheet, true);
	this->sprite.setTextureRect(this->startRect);
}



//Constructors & Destructors

Animation::Animation(sf::Sprite& sprite, sf::Texture& textureSheet,
	float animation_timer,
	u_short startFrameX, u_short startFrameY, u_short framesX, u_short framesY, u_short textureWidth, u_short textureHeight)
	: sprite(sprite), textureSheet(textureSheet),
	animationTimer(animation_timer), timer(0.f),
	textureWidth(textureWidth), textureHeight(textureHeight)
{
	this->startRect = sf::IntRect(startFrameX * textureWidth, startFrameY * textureHeight, textureWidth, textureHeight);
	this->currentRect = this->startRect;
	this->endRect = sf::IntRect(framesX * textureWidth, framesY * textureHeight, textureWidth, textureHeight);

	this->initSprite(this->startRect);
	
}

auto Animation::play(const float& dt) -> void{
	//Update timer
	this->timer  += 700.f * dt;
	if (this->timer >= this->animationTimer) {
		//Reset timer
		this->timer = 0.f;
		//Move a frame
		if (this->currentRect != this->endRect)
			currentRect.left += this->textureWidth;
		else currentRect = this->startRect;
	}

	this->sprite.setTextureRect(this->currentRect);
}

auto Animation::reset() -> void{
	this->timer = 0.f;
	this->currentRect = this->startRect;
	
}
