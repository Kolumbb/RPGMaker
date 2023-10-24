#pragma once
#include "State.h"
class SettingsState :
    public State{

private:
    //Variables & Resources
    sf::Texture texture;
    sf::RectangleShape shape;
    std::map<std::string, gui::Button*> buttons;
    //Private functions

    //Initializers
    auto initBackground() -> void;
    auto initKeyBinds() -> void;
    auto initButtons() -> void;


    //Update methods
    auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateKeyBindsInput(const float& dt) -> void;

    //Render methods
    auto render(sf::RenderTarget& target) -> void;
    auto renderButtons(sf::RenderTarget& target) -> void;

protected:

public:

    SettingsState(StateData* state_data);
    ~SettingsState();
};

