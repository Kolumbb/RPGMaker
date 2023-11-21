#pragma once
#include "../stdafx.hpp"
#include "MainMenuState.hpp"
#include "../gui/PauseMenu.hpp"
#include "../entities/Player.hpp"



class GameState :
    public State{
private:
    //Variables & Resources

    std::unique_ptr <PauseMenu> pMenu;
    std::unique_ptr<Player> player;

    //Accessors & Modifiers

    
    //Initializers
    auto initKeyBinds(std::filesystem::path path) -> void;
    auto initPlayer(float pos_x, float pos_y);
    auto initPausedMenu() -> void;
    auto makeFullScreen() -> void;


    
    //Update methods
    auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updatePaused(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateUserInput(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateUnPaused(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateKeyBindsInput(const float& dt) -> void;

    //Render methods
    auto render(sf::RenderTarget& target) -> void;
    auto renderPaused(sf::RenderTarget& target) -> void;
    auto renderUnPaused(sf::RenderTarget& target) -> void;

protected:

public:

    GameState(StateData& state_data);
    ~GameState() = default;

};

