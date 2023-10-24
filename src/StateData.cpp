#include "stdafx.h"
#include "StateData.h"








//Constructors & Destructors
GFXSettings::GFXSettings() {}

//Public methods
void GFXSettings::saveToFile(std::filesystem::path path) {
	std::ofstream ofs(path);
	if (ofs.is_open()) {
		ofs << this->title;
		ofs << this->resolution.width << this->resolution.height;
		ofs << this->frameRateLimit;
		ofs << this->verdicalSync;
		ofs << this->fullScreen;
		ofs << this->contextSettings.antialiasingLevel;
		ofs.close();
	}
	else MessageBox(HWND(), "Sorry, we couldn't find your display settings configuration while saving, please check the file location", "Error", MB_ICONWARNING);

}

void GFXSettings::loadFromFile(std::filesystem::path path) {
	std::ifstream ifs(path);
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> this->resolution.width >> this->resolution.height;
		ifs >> this->frameRateLimit;
		ifs >> this->verdicalSync;
		ifs >> this->fullScreen;
		ifs >> this->contextSettings.antialiasingLevel;
		ifs.close();
	}
	else MessageBox(HWND(), "Sorry, we couldn't find your display settings configuration while loading, please check the file location", "Error", MB_ICONWARNING);
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