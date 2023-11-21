#pragma once



/*
	GFXSettings is a container with all graphical settings of the game. Class includes load and save methods
	that gives the user posibility to change it in settings state.
*/
class GFXSettings {
private:
	
public:
	//Variables & Resources
	std::string title;
	sf::VideoMode resolution;
	bool fullScreen;
	unsigned int frameRateLimit;
	bool verdicalSync;
	sf::ContextSettings contextSettings;
	std::vector<sf::VideoMode> videoModes;

	//Constructors & Destructors
	GFXSettings();
	~GFXSettings();
	//Public methods
	void saveToFile(const std::filesystem::path path);
	void loadFromFile(const std::filesystem::path path);

};

/*
	StateData is a container for state system resources. Contains the most important resources that the state system
	requiers for running.
*/

class StateData {
private:
	//Initializers
	auto initFont(std::filesystem::path path) -> void;
	auto initSupportedKeys(std::filesystem::path path) -> void;
	auto initWindow() -> void;
	auto initGFXSettings() -> void;

public:
	//Variables & Resources
	
	std::stack<std::shared_ptr<State>> states;
	std::shared_ptr<sf::RenderWindow> window;
	std::map<std::string, int> supportedKeys;
	std::shared_ptr <GFXSettings> gfxSettings;
	sf::Font font;
	
	//Constructors & Destructors
	StateData();
	~StateData();
};





