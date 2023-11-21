#include "AnimationComponent.hpp"

/*
	The idea of animation component is that you can store here textures/sprites from
	entity class and store here all sets of animations. By addAnimation method you can
	add entities textures outside of AnimationComponent class, and for play method you
	can get access to play method from Animation class that is
	just counts in certain time when it should switch intRect position of
	texture that is rendering.
*/

//Constructors & Destructors
AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
	: sprite(sprite), textureSheet(textureSheet){

}

//Other public methods
auto AnimationComponent::play(const std::string animationName, const float& dt) -> void{
	this->animations[animationName]->play(dt);
}

auto AnimationComponent::addAnimation(
	const std::string animationName, float animationTimer, 
	u_short startFrameX, u_short startFrameY, 
	u_short framesX, u_short framesY, 
	u_short textureWidth, u_short textureHeight
) -> void{
	this->animations[animationName] = std::make_unique<Animation>(
		this->sprite, this->textureSheet,
		animationTimer, startFrameX, startFrameY, 
		framesX, framesY, textureWidth, textureHeight
	);
}
