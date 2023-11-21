#pragma once

#include "../stdafx.hpp"
#include "../Animation.hpp"

class AnimationComponent {
private:
	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	
	std::map<std::string, std::unique_ptr<Animation>> animations;
public:
	//Constructors & Destructors
	AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
	~AnimationComponent() = default;




	//Other public methods
	auto play(const std::string animationName, const float& dt) -> void;
	auto addAnimation(
		const std::string animationName,float animationTimer, 
		u_short startFrameX, u_short startFrameY, 
		u_short framesX, u_short framesY, 
		u_short textureWidth, u_short textureHeight
	) -> void;

};