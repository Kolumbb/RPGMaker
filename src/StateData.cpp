#include "stdafx.h"
#include "StateData.h"








//Constructors & Destructors
GFXSettings::GFXSettings() {}

//Public methods
void GFXSettings::saveToFile(std::filesystem::path path) {
	auto ofs = std::ofstream(path);

	assert(ofs);

	if (ofs) {
		ofs << this->title;
		ofs << this->resolution.width << this->resolution.height;
		ofs << this->frameRateLimit;
		ofs << this->verdicalSync;
		ofs << this->fullScreen;
		ofs << this->contextSettings.antialiasingLevel;
	}
	ofs.close();

}

void GFXSettings::loadFromFile(std::filesystem::path path) {
	auto ifs = std::ifstream(path);

	assert(ifs);

	if (ifs) {
		std::getline(ifs, title);
		ifs >> this->resolution.width >> this->resolution.height;
		ifs >> this->frameRateLimit;
		ifs >> this->verdicalSync;
		ifs >> this->fullScreen;
		ifs >> this->contextSettings.antialiasingLevel;
	}
	ifs.close();
}


//StateData class

//Constructors & Destructors
StateData::StateData() {
	this->states = std::make_unique<std::stack<State*>>();
	this->supportedKeys = std::make_unique<std::map<std::string, int>>();
}

StateData::~StateData() {
	while (!this->states->empty()) {
		this->states->pop();
	}
}