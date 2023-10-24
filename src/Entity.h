#pragma once
class Entity{
	enum EntityType {PLAYER = 0, ENEMY} entityType;
private:
	//Variables & Resources
protected:
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Texture textureSheet;
	
	sf::IntRect startRect;




	//Initializers


public:
	
	//Constructors & Destructors
	Entity(float pos_x, float pos_y);
	virtual ~Entity();

	//Update methods
	virtual void update(const float& dt, const sf::Vector2f& mouse_position) = 0;
	//Render methods
	virtual void render(sf::RenderTarget& target) = 0;
};

