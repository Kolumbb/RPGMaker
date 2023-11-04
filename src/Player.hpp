#pragma once
#include "Entity.hpp"
#include "MovementComponent.hpp"

class Player :
    public Entity {

private:
    //Resources & Variables
    sf::Vector2f velocity;
    std::map<std::string, int> keyBinds;
    MovementComponent* movementComponent;
    Direction direction;
    //Initializers
    void initStartRect();
    void initMovementComponent();


protected:
public:
    //Constructors & Destructors
    Player(float pos_x, float pos_y, std::map<std::string, int>& key_binds);
    ~Player();

    //Update methods
    auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateUserInput(const float& dt) -> void;
    //Render methods
    auto render(sf::RenderTarget& target) -> void;
};

