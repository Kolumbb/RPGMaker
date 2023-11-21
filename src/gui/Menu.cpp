#include "Menu.hpp"


//Menu Class

//Getters & Modifiers
auto Menu::getMenu() -> const bool const{
	return this->menu;
}

auto Menu::setMenu(bool yn) -> void{
	this->menu = yn;
}

//Constructors & Destructors

Menu::Menu(StateData& state_data, bool menu) : stateData(state_data), menu(menu) {};

Menu::~Menu() {
	if (!this->buttons.empty()) {
		for (auto& it : this->buttons)
			delete it.second;
	}
	this->buttons.clear();
}