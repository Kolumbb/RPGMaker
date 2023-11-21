#pragma once
#include "../stdafx.hpp"
#include "State.hpp"
#include "GameState.hpp"
#include "SettingsState.hpp"


class MainMenuState :
    public State{

private:
    //Variables & Resources
    sf::RectangleShape shape;
    std::map<std::string, gui::Button*> buttons;
    //Private functions

    //Initializers
    auto initBackground(std::filesystem::path path) -> void;
    auto initKeyBinds(std::filesystem::path path) -> void;
    auto initButtons() -> void;


    //Update methods
    auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void;

    //Render methods
    auto render(sf::RenderTarget& target) -> void;
    auto renderButtons(sf::RenderTarget& target) -> void;

protected:

public:

    MainMenuState(StateData& state_data);
    ~MainMenuState();

};

