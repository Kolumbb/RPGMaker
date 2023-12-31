#include "State.hpp"

//Private methods


auto State::updateKeyTime(const float& dt) -> void {
	this->keyTime += 80 * dt;
}

//Initializers

//Accessors
auto State::getKeyTime(const float& dt) -> bool const {
	if (this->keyTime > this->keyTimeMax) {
		this->keyTime = 1;
		return true;
	}
	return false;
}



State::State(StateData& state_data): stateData(state_data){
	this->keyTime = 1;
	this->keyTimeMax = 10;
};

State::~State(){

}










