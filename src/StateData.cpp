#include "StateData.hpp"
#include "stdafx.hpp"

//GFXSettings class

//Constructors & Destructors
GFXSettings::GFXSettings() {

	this->title = "Platformer";
	auto path = std::filesystem::path("..\\..\\..\\..\\Resources\\Config\\display_settings.ini");
	auto ifs = std::ifstream(path);
	if (ifs) {
		ifs >> this->resolution.width >> this->resolution.height;
		ifs >> this->frameRateLimit;
		ifs >> this->verdicalSync;
		ifs >> this->fullScreen;
		ifs >> this->contextSettings.antialiasingLevel;
	}
	ifs.close();
}

GFXSettings::~GFXSettings(){

}

//Public methods
void GFXSettings::saveToFile(
	std::filesystem::path path = "..\\..\\..\\..\\Resources\\Config\\display_settings.ini"
) {
	auto fs = std::fstream(path);

	if (fs) {
		fs << this->resolution.width << this->resolution.height;
		fs << this->frameRateLimit;
		fs << this->verdicalSync;
		fs << this->fullScreen;
		fs << this->contextSettings.antialiasingLevel;
	}
	fs.close();

}

auto GFXSettings::loadFromFile(
	std::filesystem::path path = "..\\..\\..\\..\\Resources\\Config\\display_settings.ini"
) -> void{

	auto ifs = std::ifstream(path);
	if (ifs.good()) {
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

auto StateData::initFont(
	std::filesystem::path path = "..\\..\\..\\..\\Resources\\Fonts\\OpenSans-Regular.ttf"
	) -> void{
	this->font.loadFromFile(path.string());
}

auto StateData::initSupportedKeys(
	std::filesystem::path path = "..\\..\\..\\..\\Resources\\config\\supported_keys.ini"
) -> void {

	auto file = std::fstream(path);
	auto key = std::string("");
	auto key_value = int(0);

	if (file) {
		while (file >> key >> key_value)
			this->supportedKeys[key] = key_value;
	}

	file.close();

	/*for (auto& it : this->supportedKeys) {
		std::cout << it.first << " " << it.second << std::endl;
	}*/
}

auto StateData::initWindow() -> void{
	this->window = std::make_shared<sf::RenderWindow>(
		this->gfxSettings->resolution,
		this->gfxSettings->title,
		this->gfxSettings->fullScreen,
		this->gfxSettings->contextSettings
	);
}

auto StateData::initGFXSettings() -> void{
	this->gfxSettings = std::make_shared<GFXSettings>();
}

//Constructors & Destructors
StateData::StateData() {
	this->initSupportedKeys();
	this->initFont();
	this->initGFXSettings();
	this->initWindow();
}

StateData::~StateData() {
	while (!this->states.empty())
		this->states.pop();
}