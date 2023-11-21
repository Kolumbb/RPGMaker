#pragma once
#include "../stdafx.hpp"
#include "../gui/DisplaySettingsMenu.hpp"
#include "State.hpp"
class SettingsState :
    public State{

private:
    //Variables & Resources
    std::unique_ptr < sf::RectangleShape> background;
    std::map<std::string, gui::Button*> buttons;
    std::unique_ptr <DisplaySettingsMenu> dMenu;
    //Private functions

    //Initializers

    auto initBackground(std::filesystem::path path) -> void;
    auto initKeyBinds(std::filesystem::path path) -> void;
    auto initButtons() -> void;
    auto initDisplaySettingsMenu() -> void;


    //Update methods
    auto update(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateDisplaySettings(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateSettingsState(const float& dt, const sf::Vector2f& mouse_position) -> void;


    auto updateButtons(const float& dt, const sf::Vector2f& mouse_position) -> void;
    auto updateKeyBindsInput(const float& dt) -> void;

    //Render methods
    auto render(sf::RenderTarget& target) -> void;
    auto renderDisplaySettings(sf::RenderTarget& target) -> void;
    auto renderSettingsState(sf::RenderTarget& target) -> void;
    auto renderButtons(sf::RenderTarget& target) -> void;
protected:

public:

    SettingsState(StateData& state_data);
    ~SettingsState();
};

