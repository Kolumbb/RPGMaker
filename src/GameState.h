#pragma once

#include "State.h"
#include"MainMenuState.h"
#include "Player.h"


class GameState :
    public State{
private:
    //Variables & Resources
    gui::PauseMenu* pMenu;
    bool paused;
    sf::RectangleShape shape;
    Player* player;
    //Private functions
    
    //Initializers
    auto initBackground() -> void;
    auto initKeyBinds() -> void;
    auto initPlayer() -> void;
    auto initPausedMenu() -> void;

    //Accessors & Modifiers
    auto getPaused() -> bool;
    auto setPaused(bool yn) -> void;
    
    //Update methods
    auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updatePaused(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateUnPaused(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateKeyBindsInput(const float& dt) -> void;

    //Render methods
    auto render(sf::RenderTarget& target) -> void;
    auto renderPaused(sf::RenderTarget& target) -> void;
    auto renderUnPaused(sf::RenderTarget& target) -> void;

protected:

public:

    GameState(StateData* state_data);
    ~GameState();

};

